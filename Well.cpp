/*
 * Well.cpp
 *
 *  Created on: 31.05.2014
 *      Author: basyak
 */

#include "Well.h"

Well::Well() : width(WELL_WIDTH), height(WELL_HEIGHT), x(0), y(0) {
	mask = new bool *[WELL_HEIGHT / CUBE_S];
	for(int i = 0; i < WELL_HEIGHT / CUBE_S; ++i) {
		mask[i] = new bool[WELL_WIDTH / CUBE_S];
		for(int j = 0; j < WELL_WIDTH / CUBE_S; ++j) {
			mask[i][j] = false;
		}
	}
	well = shared_ptr<SDL_Surface> (SDL_CreateRGBSurface(SDL_SWSURFACE, width, height, SCREEN_BPP, 0, 0, 0, 0));
	SDL_FillRect(well.get(), &well->clip_rect, SDL_MapRGB(screen->format, 0, 0, 0));
}

Well::~Well() {
	for(int i = 0; i < WELL_HEIGHT / CUBE_S; ++i) {
		delete[] mask[i];
	}
	delete[] mask;
}

void Well::show() {
	check_lines();
	draw();
	apply_surface(x, y, well.get(), screen.get(), NULL);
}

void Well::unite(shared_array<SDL_Rect> box, int x, int y) {
	for (int i = 0; i < 4; ++i) {
		int k = (y + box[i].y) / CUBE_S;
		int l = (x + box[i].x) / CUBE_S;
		mask[k][l] = true;
	}
}

void Well::draw() {
	Uint32 color = 0xC0C0C0;
	SDL_FillRect(well.get(), &well->clip_rect, SDL_MapRGB(screen->format, 0, 0, 0));
	for(int i = 0; i < WELL_HEIGHT / CUBE_S; ++i) {
		for(int j = 0; j < WELL_WIDTH / CUBE_S; ++j) {
			if(mask[i][j] == true) {
				draw_cube(well.get(), (j * CUBE_S), (i * CUBE_S), color);
			}
		}
	}
}

void Well::check_lines() {
	bool **temp = new bool *[WELL_HEIGHT / CUBE_S];
	for(int i = 0; i < WELL_HEIGHT / CUBE_S; ++i) {
		temp[i] = new bool[WELL_WIDTH / CUBE_S];
		for(int j = 0; j < WELL_WIDTH / CUBE_S; ++j) {
			temp[i][j] = false;
		}
	}
	int true_count = 0;
	int k = WELL_HEIGHT / CUBE_S - 1;
	for(int i = WELL_HEIGHT / CUBE_S - 1; i >= 0; --i) {
		true_count = 0;
		for(int j = WELL_WIDTH / CUBE_S - 1; j >= 0; --j) {
			if(mask[i][j] == true) {
				++true_count;
			}
		}
		if(true_count != WELL_WIDTH / CUBE_S) {
			for(int l = WELL_WIDTH / CUBE_S - 1; l >= 0; --l) {
				temp[k][l] = mask[i][l];
			}
			--k;
		}
	}
	for(; k >= 0; --k) {
		for(int l = WELL_WIDTH / CUBE_S - 1; l >=0; --l) {
			temp[k][l] = false;
		}
	}
	for(int i = 0; i < WELL_HEIGHT / CUBE_S; ++i) {
		delete[] mask[i];
	}
	delete[] mask;
	mask = temp;
}


