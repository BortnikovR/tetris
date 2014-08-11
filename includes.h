/*
 * includes.h
 *
 *  Created on: 31.05.2014
 *      Author: basyak
 */
#pragma once
#ifndef INCLUDES_H_
#define INCLUDES_H_

#include <iostream>
#include <boost/shared_array.hpp>
#include <boost/shared_ptr.hpp>
#include <SDL/SDL.h>
#include <SDL/SDL_draw.h>
#include <string>
#include <vector>

using namespace boost;

extern int const WELL_HEIGHT;
extern int const WELL_WIDTH;
extern int const CUBE_S;
extern int const SCREEN_BPP;
extern int const FRAMES_PER_SECOND;
extern SDL_Event event;
extern shared_ptr<SDL_Surface> screen;

typedef int tetra_type;
extern tetra_type tetra_id[];

typedef Uint32 color;
extern color c[];

extern bool init();

extern void clean_up();

extern void apply_surface(int x, int y, SDL_Surface *source, SDL_Surface *destination, SDL_Rect *clip);

extern void draw_cube(SDL_Surface *surf, int x, int y, Uint32 color);

#endif /* INCLUDES_H_ */
