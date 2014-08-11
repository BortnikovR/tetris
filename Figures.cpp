/*
 * Figures.cpp
 *
 *  Created on: 01.06.2014
 *      Author: basyak
 */
#include "Figures.h"

Line::Line() : Tetramino() {
	for(int i = 0; i < 4; ++i) {
		box[i].x = i * CUBE_S;
		box[i].y = CUBE_S;
	}
	draw();
}

void Line::rotate() {
	angle += 90;
	if(angle >= 360) {
		angle = 0;
	}
	if(angle == 0 or angle == 180) {
		for(int i = 0; i < 4; ++i) {
			box[i].x = i * CUBE_S;
			box[i].y = CUBE_S;
		}
	} else if(angle == 90 or angle == 270) {
		for(int i = 0; i < 4; ++i) {
			box[i].x = 2 * CUBE_S;
			box[i].y = i * CUBE_S;
		}
	}
	draw();
}

Block::Block() : Tetramino() {
	for(int i = 0; i < 4; ++i) {
		box[0].x = box[2].x = CUBE_S;
		box[1].x = box[3].x = 2 * CUBE_S;
		box[0].y = box[1].y = CUBE_S;
		box[2].y = box[3].y = 2 * CUBE_S;
	}
	draw();
}

Pyramid::Pyramid() : Tetramino() {
	for(int i = 0; i < 4; ++i) {
		box[0].x = CUBE_S;
		box[1].x = 2 * CUBE_S;
		box[2].x = 3 * CUBE_S;
		box[0].y = box[1].y = box[2].y = CUBE_S;
		box[3].x = box[3].y = 2 *CUBE_S;
	}
	draw();
}

void Pyramid::rotate() {
	angle += 90;
	if(angle >= 360) {
		angle = 0;
	}
	if(angle == 0) {
		box[0].x = CUBE_S;
		box[1].x = 2 * CUBE_S;
		box[2].x = 3 * CUBE_S;
		box[0].y = box[1].y = box[2].y = CUBE_S;
		box[3].x = box[3].y = 2 *CUBE_S;
	} else if(angle == 180) {
		box[1].x = CUBE_S;
		box[2].x = 2 * CUBE_S;
		box[3].x = 3 * CUBE_S;
		box[1].y = box[2].y = box[3].y = CUBE_S;
		box[0].x = 2 * CUBE_S;
		box[0].y = 0;
	} else if(angle == 90) {
		box[0].x = box[1].x = box[3].x = 2 * CUBE_S;
		box[2].x = 3 * CUBE_S;
		box[0].y = 0;
		box[1].y = box[2].y = CUBE_S;
		box[3].y = 2 * CUBE_S;
	} else if(angle == 270) {
		box[0].x = box[2].x = box[3].x = 2 * CUBE_S;
		box[1].x = CUBE_S;
		box[0].y = 0;
		box[1].y = box[2].y = CUBE_S;
		box[3].y = 2 * CUBE_S;
	}
	draw();
}

LeftL::LeftL() : Tetramino() {
	for(int i = 0; i < 4; ++i) {
		box[0].x = box[3].x = CUBE_S;
		box[0].y = box[1].y = box[2].y = CUBE_S;
		box[1].x = 2 * CUBE_S;
		box[2].x = 3 * CUBE_S;
		box[3].y = 2 * CUBE_S;
	}
	draw();
}

void LeftL::rotate() {
	angle += 90;
	if(angle >= 360) {
		angle = 0;
	}
	if(angle == 0) {
		box[0].x = box[3].x = CUBE_S;
		box[0].y = box[1].y = box[2].y = CUBE_S;
		box[1].x = 2 * CUBE_S;
		box[2].x = 3 * CUBE_S;
		box[3].y = 2 * CUBE_S;
	} else if(angle == 180) {
		box[0].x = box[3].x = 3 * CUBE_S;
		box[3].y = box[1].y = box[2].y = CUBE_S;
		box[1].x = CUBE_S;
		box[2].x = 2 * CUBE_S;
		box[0].y = 0;
	} else if(angle == 90) {
		box[0].x = box[1].x = box[2].x = 2 * CUBE_S;
		box[0].y = 0;
		box[1].y = CUBE_S;
		box[2].y = box[3].y = 2 * CUBE_S;
		box[3].x = 3 * CUBE_S;
	} else if(angle == 270) {
		box[3].x = box[1].x = box[2].x = 2 * CUBE_S;
		box[0].y = box[1].y = 0;
		box[3].y = 2 * CUBE_S;
		box[2].y = CUBE_S;
		box[0].x = CUBE_S;
	}
	draw();
}

RightL::RightL() : Tetramino() {
	for(int i = 0; i < 4; ++i) {
		box[0].x = CUBE_S;
		box[0].y = box[1].y = box[2].y = CUBE_S;
		box[1].x = 2 * CUBE_S;
		box[2].x = box[3].x = 3 * CUBE_S;
		box[3].y = 2 * CUBE_S;
	}
	draw();
}

void RightL::rotate() {
	angle += 90;
	if(angle >= 360) {
		angle = 0;
	}
	if(angle == 0) {
		box[0].x = CUBE_S;
		box[0].y = box[1].y = box[2].y = CUBE_S;
		box[1].x = 2 * CUBE_S;
		box[2].x = box[3].x = 3 * CUBE_S;
		box[3].y = 2 * CUBE_S;
	} else if(angle == 180) {
		box[0].x = box[1].x = CUBE_S;
		box[3].y = box[1].y = box[2].y = CUBE_S;
		box[3].x = 3 * CUBE_S;
		box[2].x = 2 * CUBE_S;
		box[0].y = 0;
	} else if(angle == 90) {
		box[0].x = box[2].x = box[3].x = 2 * CUBE_S;
		box[0].y = box[1].y = 0;
		box[2].y = CUBE_S;
		box[3].y = 2 * CUBE_S;
		box[1].x = 3 * CUBE_S;
	} else if(angle == 270) {
		box[0].x = box[1].x = box[3].x = 2 * CUBE_S;
		box[0].y = 0;
		box[3].y = box[2].y = 2 * CUBE_S;
		box[1].y = CUBE_S;
		box[2].x = CUBE_S;
	}
	draw();
}

LeftZ::LeftZ() : Tetramino() {
	for(int i = 0; i < 4; ++i) {
		box[0].x = CUBE_S;
		box[1].x = box[2].x = 2 * CUBE_S;
		box[0].y = box[1].y = CUBE_S;
		box[3].x = 3 * CUBE_S;
		box[2].y = box[3].y = 2 *CUBE_S;
	}
	draw();
}

void LeftZ::rotate() {
	angle += 90;
	if(angle >= 360) {
		angle = 0;
	}
	if(angle == 0 or angle == 180) {
		box[0].x = CUBE_S;
		box[1].x = box[2].x = 2 * CUBE_S;
		box[0].y = box[1].y = CUBE_S;
		box[3].x = 3 * CUBE_S;
		box[2].y = box[3].y = 2 *CUBE_S;
	} else if(angle == 90 or angle == 270) {
		box[0].x = box[2].x = 3 * CUBE_S;
		box[0].y = 0;
		box[1].y = box[2].y = CUBE_S;
		box[1].x = box[3].x = 2 * CUBE_S;
		box[3].y = 2 * CUBE_S;
	}
	draw();
}

RightZ::RightZ() : Tetramino() {
	for(int i = 0; i < 4; ++i) {
		box[0].x = box[3].x = 2 * CUBE_S;
		box[0].y = box[1].y = CUBE_S;
		box[1].x = 3 * CUBE_S;
		box[2].x = CUBE_S;
		box[2].y = box[3].y = 2 * CUBE_S;
	}
	draw();
}

void RightZ::rotate() {
	angle += 90;
	if(angle >= 360) {
		angle = 0;
	}
	if(angle == 0 or angle == 180) {
		box[0].x = box[3].x = 2 * CUBE_S;
		box[0].y = box[1].y = CUBE_S;
		box[1].x = 3 * CUBE_S;
		box[2].x = CUBE_S;
		box[2].y = box[3].y = 2 * CUBE_S;
	} else if(angle == 90 or angle == 270) {
		box[0].x = box[1].x = 2 * CUBE_S;
		box[0].y = 0;
		box[1].y = box[2].y = CUBE_S;
		box[2].x = box[3].x = 3 * CUBE_S;
		box[3].y = 2 * CUBE_S;
	}
	draw();
}


