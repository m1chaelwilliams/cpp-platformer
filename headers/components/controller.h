#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <raylib.h>

class PlatformerController {

	public:
	
	bool left, right, jump;

	int key_left, key_right, key_jump;

	PlatformerController(
		int key_left,
		int key_right,
		int key_jump
	) :
		key_left(key_left),
		key_right(key_right),
		key_jump(key_jump)
	{}

	void update() {
		left = IsKeyDown(key_left);
		right = IsKeyDown(key_right);
		jump = IsKeyPressed(key_jump);
	}

};

#endif