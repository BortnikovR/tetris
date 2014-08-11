/*
 * Game.cpp
 *
 *  Created on: 01.06.2014
 *      Author: basyak
 */

#include "Game.h"
#include "Well.h"
#include "Tetramino.h"
#include "Timer.h"

Game::Game() : lvl(1), started(false), paused(false), stopped(false) {}

//Main loop
int Game::start() {
	if(init() == false) {
		return -1;
	}

	srand(time(NULL));

	bool quit = false;

	Well well;
	if(well.get_surf() == NULL) {
		return 1;
	}

	Timer fps;
	Timer delta;

	if(SDL_EnableKeyRepeat(100, 25) == -1) {
		return 1;
	}
	delta.start();

	while(!quit) {
		tetra_type tetra_id = rand() % 7;
		TetraminoFactory tetramino_factory;
		shared_ptr<Tetramino> tetramino (new Tetramino);
		tetramino = tetramino_factory.createTetramino(tetra_id);
		if(tetramino->get_surf() == NULL) {
			return -1;
		}
		while(!tetramino->is_fallen() && !quit) {
			fps.start();
			while(SDL_PollEvent(&event)) {
				tetramino->handle_input();
				if(event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE) {
					quit = true;
				}
			}
			tetramino->move(delta.get_ticks(), lvl, well.get_mask());
			delta.start();
			SDL_FillRect(screen.get(), &screen->clip_rect, SDL_MapRGB(screen->format, 255, 255, 255));
			well.show();
			tetramino->show();
			if(SDL_Flip(screen.get()) == -1) {
				return 1;
			}
			if(fps.get_ticks() < 1000 / FRAMES_PER_SECOND) {
				SDL_Delay(1000 / FRAMES_PER_SECOND - fps.get_ticks());
			}
			tetramino->incr_frames();
		}
		well.unite(tetramino->get_box(), (int)tetramino->get_x(), (int)tetramino->get_y());
		well.show();
		if(SDL_Flip(screen.get()) == -1) {
			return 1;
		}
	}

	clean_up();

	return 0;
}


