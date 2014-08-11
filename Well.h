/*
 * Well.h
 *
 *  Created on: 31.05.2014
 *      Author: basyak
 */

#ifndef WELL_H_
#define WELL_H_

#include "includes.h"

class Well {
	int width;
	int height;
	int x;
	int y;
	bool **mask;
	shared_ptr<SDL_Surface> well;

public:
	Well();
	~Well();

	int get_width() { return width; }
	int get_height() { return height; }
	bool **get_mask() { return mask; }
	shared_ptr<SDL_Surface> get_surf() { return well; }

	void set_w_h(int w, int h) {
		width = w;
		height = h;
	}

	void draw();
	void check_lines();
	void show();
	void unite(shared_array<SDL_Rect> box, int x, int y);
};


#endif /* WELL_H_ */
