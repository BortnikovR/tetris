/*
 * Timer.h
 *
 *  Created on: 31.05.2014
 *      Author: basyak
 */

#ifndef TIMER_H_
#define TIMER_H_
#include "includes.h"

class Timer {
	int startTicks;
	int pausedTicks;
	bool paused;
	bool started;

public:
	Timer();
	void start();
	void stop();
	void pause();
	void unpause();
	bool is_paused();
	bool is_started();
	int get_ticks();
};


#endif /* TIMER_H_ */
