/*
 * Figures.h
 *
 *  Created on: 01.06.2014
 *      Author: basyak
 */
#pragma once
#ifndef FIGURES_H_
#define FIGURES_H_
#include "includes.h"
#include "Tetramino.h"

class Line : public Tetramino {
public:
	Line();
	void rotate();
};

class Block : public Tetramino {
public:
	Block();
};

class Pyramid : public Tetramino {
public:
	Pyramid();
	void rotate();
};

class LeftL : public Tetramino {
public:
	LeftL();
	void rotate();
};

class RightL : public Tetramino {
public:
	RightL();
	void rotate();
};

class LeftZ : public Tetramino {
public:
	LeftZ();
	void rotate();
};

class RightZ : public Tetramino {
public:
	RightZ();
	void rotate();
};

#endif /* FIGURES_H_ */
