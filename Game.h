/*
 * Game.h
 *
 *  Created on: 01.06.2014
 *      Author: basyak
 */
#pragma once
#ifndef GAME_H_
#define GAME_H_

#include "includes.h"

class Game {
	int lvl;
	bool started;
	bool paused;
	bool stopped;

public:
	Game();
	int getlvl() { return lvl;}
	bool is_started() { return started; }
	bool is_paused() { return paused; }
	bool is_stopped() { return stopped; }

	int start();
	void pause();
	void restart();
};


#endif /* GAME_H_ */
