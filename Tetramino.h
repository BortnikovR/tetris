/*
 * Tetramino.h
 *
 *  Created on: 31.05.2014
 *      Author: basyak
 */
#pragma once
#ifndef TETRAMINO_H_
#define TETRAMINO_H_

#include "includes.h"

class Tetramino {
protected:
	shared_array<SDL_Rect> box;		// Массив блоков, из которых состоит фигура
	shared_ptr<SDL_Surface> tetramino;	// Поверхность, на которой рисуется фигура
	float x;
	float y;
	float xVel;
	float yVel;
	int frames;
	int x_move_flag;	// -1 -> moving left	1 -> moving right
	int angle;
	bool down_pressed;
	bool fallen;
	Uint32 t_color;

public:
	Tetramino();
	virtual ~Tetramino() {};

	void show();
	void move(Uint32 deltaticks, int lvl, bool **mask = NULL);
	void handle_input();
	void check_y_collision(bool **mask = NULL);		// Проверка
	void check_x_collision(bool **mask = NULL);		// коллизий
	void draw();									// Отрисовка фигуры
	void incr_frames() { ++frames; }
	virtual void rotate();

	bool is_fallen() { return fallen; }
	float get_x() { return x; }
	float get_y() { return y; }
	virtual shared_array<SDL_Rect> get_box() { return box; }
	shared_ptr<SDL_Surface> get_surf() { return tetramino; }
};

class TetraminoFactory {
public:
	TetraminoFactory(){};
	virtual ~TetraminoFactory(){};
	virtual shared_ptr<Tetramino> createTetramino(tetra_type id);
};

#endif /* TETRAMINO_H_ */
