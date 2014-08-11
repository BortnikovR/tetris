/*
 * Tetramino.cpp
 *
 *  Created on: 31.05.2014
 *      Author: basyak
 */
#include "Tetramino.h"
#include "Figures.h"


Tetramino::Tetramino() {
	x = WELL_WIDTH / 2 - 2 * CUBE_S;
	y = 0;
	xVel = 0;
	yVel = CUBE_S;
	frames = 0;
	x_move_flag = 0;
	angle = 0;
	t_color = c[rand() % 6];
	down_pressed = fallen = false;
	tetramino = shared_ptr<SDL_Surface> (SDL_CreateRGBSurface(SDL_SWSURFACE, 4 * CUBE_S, 4 * CUBE_S, SCREEN_BPP, 0, 0, 0, 0));
	SDL_FillRect(tetramino.get(), &tetramino->clip_rect, SDL_MapRGB(screen->format, 0, 0, 0));
	box = shared_array<SDL_Rect> (new SDL_Rect[4]);
	for(int i = 0; i < 4; ++i) {
		box[i].x = box[i].y = 0;
		box[i].h = box[i].w = CUBE_S;
	}
	draw();
}

void Tetramino::draw() {
	SDL_FillRect(tetramino.get(), &tetramino->clip_rect, SDL_MapRGB(screen->format, 0, 0, 0));
	if(tetramino != NULL) {
		Uint32 colorkey = SDL_MapRGB(screen->format, 0, 0, 0);
		SDL_SetColorKey(tetramino.get(), SDL_SRCCOLORKEY, colorkey);
	}
	for(int i = 0; i < 4; ++i) {
		draw_cube(tetramino.get(), box[i].x, box[i].y, t_color);
	}
}

void Tetramino::show() {
	apply_surface((int)x, (int)y, tetramino.get(), screen.get(), NULL);
}

void Tetramino::move(Uint32 deltaticks, int lvl, bool **mask) {
	check_x_collision(mask);
	x_move_flag = 0;

	if(down_pressed == true) {
		y += yVel * (deltaticks / 1000.f);
	} else if(frames == FRAMES_PER_SECOND / (1 + lvl)) {
		y += yVel;
		frames = 0;
	}
	check_y_collision(mask);
}

void Tetramino::handle_input() {
	if(event.type == SDL_KEYDOWN) {
		switch(event.key.keysym.sym) {
			case SDLK_LEFT:
				x -= CUBE_S;
				x_move_flag = -1;
				break;
			case SDLK_RIGHT:
				x += CUBE_S;
				x_move_flag = 1;
				break;
			case SDLK_DOWN:
				yVel = 25 * CUBE_S;
				down_pressed = true;
				break;
			case SDLK_UP:
				rotate();
				break;
			default: break;
		}
	} else if(event.type == SDL_KEYUP) {
		switch(event.key.keysym.sym) {
			case SDLK_LEFT:
				xVel = 0;
				break;
			case SDLK_RIGHT:
				xVel = 0;
				break;
			default: break;
		}
	}
}

void Tetramino::check_y_collision(bool **mask) {
	for(int i = 0; i < 4; ++i) {
		if((y + box[i].y + box[i].h > WELL_HEIGHT)) {
			y = WELL_HEIGHT - box[i].y - box[i].h;
			yVel = 0;
			frames = 0;
			fallen = true;
			return;
		}
	}

	if(mask != NULL) {
		for (int i = 0; i < 4; ++i) {
			int k = 0;
			if(down_pressed == true) {
				k = (y + box[i].y) / CUBE_S + 1;
			} else {
				k = (y + box[i].y) / CUBE_S;
			}
			int l = (x + box[i].x) / CUBE_S;
			if(k < WELL_HEIGHT / CUBE_S) {
				if(mask[k][l] == true) {
					y = (k - 1) * CUBE_S - box[i].y;
					yVel = 0;
					frames = 0;
					fallen = true;
					return;
				}
			}
		}
	}
}

void Tetramino::check_x_collision(bool **mask) {
	for(int i = 0; i < 4; ++i) {
		if((x + box[i].x) < 0) {
			x = 0 - box[i].x;
			return;
		} else if((x + box[i].x + box[i].w) > WELL_WIDTH) {
			x = WELL_WIDTH - box[i].x - box[i].w;
			return;
		}
	}
	if(mask != NULL) {
		for (int i = 0; i < 4; ++i) {
			int k = (y + box[i].y) / CUBE_S;
			int l = (x + box[i].x) / CUBE_S;
			if(k < WELL_HEIGHT / CUBE_S && l >= 0 && l <= (WELL_WIDTH / CUBE_S - 1)) {
				if(mask[k][l] == true) {
					x -= x_move_flag * CUBE_S;
					return;
				}
			}
		}
	}
}

void Tetramino::rotate() {
	angle += 90;
	if(angle >= 360) {
		angle = 0;
	}
	draw();
}

shared_ptr<Tetramino> TetraminoFactory::createTetramino(tetra_type id) {
	shared_ptr<Tetramino> p;
	switch(id) {
		case 0: p = shared_ptr<Line> (new Line); break;
		case 1: p = shared_ptr<Block> (new Block); break;
		case 2: p = shared_ptr<Pyramid> (new Pyramid); break;
		case 3: p = shared_ptr<LeftL> (new LeftL); break;
		case 4: p = shared_ptr<RightL> (new RightL); break;
		case 5: p = shared_ptr<LeftZ> (new LeftZ); break;
		case 6: p = shared_ptr<RightZ> (new RightZ); break;
		default: break;
	}
	return p;
}
