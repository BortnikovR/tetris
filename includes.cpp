/*
 * includes.cpp
 *
 *  Created on: 31.05.2014
 *      Author: basyak
 */
#include "includes.h"

int const WELL_HEIGHT = 640;
int const WELL_WIDTH = 320;
int const CUBE_S = 32;
int const SCREEN_BPP = 32;
int const FRAMES_PER_SECOND = 50;
SDL_Event event;
shared_ptr<SDL_Surface> screen(new SDL_Surface);

//Types of shapes
tetra_type tetra_id[] =	{	0,	// line
							1,	// block
							2,	// pyramid
							3,	// leftL
							4,	// rightL
							5,	// leftZ
							6,	// rightZ
						};

//Colors of shapes
color c[] =	{	0xD50000,	// red
				0x039903,	// green
				0x0080F0,	// cyan
				0xEAEA27,	// yellow
				0x891BF6,	// purple
				0xF07000	// orange
			};

//SDL initialization
bool init() {
	if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 ) {
		return false;
	}


	screen = shared_ptr<SDL_Surface> (SDL_SetVideoMode( WELL_WIDTH, WELL_HEIGHT, SCREEN_BPP, SDL_SWSURFACE ));


	if(screen.get() == NULL) {
		return false;
	}

	SDL_WM_SetCaption( "Tetris", NULL );
	return true;
}

void clean_up() {
	SDL_Quit();
}

//Displaying on the screen
void apply_surface(int x, int y, SDL_Surface *source, SDL_Surface *destination, SDL_Rect *clip = NULL) {
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;

	SDL_BlitSurface(source, clip, destination, &offset);
}

//Drawing 1 cube
void draw_cube(SDL_Surface *surf, int x, int y, Uint32 color) {
	SDL_Rect box;
	box.x = x;
	box.y = y;
	box.w = box.h = CUBE_S;
	SDL_FillRect(surf, &box, color);
	Draw_Line(surf, (box.x), (box.y), (box.x + box.w - 1), (box.y), 0x000000);
	Draw_Line(surf, (box.x + box.w - 1), (box.y), (box.x + box.w - 1), (box.y + box.h - 1), 0x000000);
	Draw_Line(surf, (box.x + box.w - 1), (box.y + box.h - 1), (box.x), (box.y + box.h - 1), 0x000000);
	Draw_Line(surf, (box.x), (box.y + box.h - 1), (box.x), (box.y), 0x000000);
}
