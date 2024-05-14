// data that is accessed throughtout the program.
// data MUST be initialized before entering the game loop
// there is not checking for valid state afterwards.

#ifndef SHAREDDATA_H
#define SHAREDDATA_H

#include "world.h"

class SharedData {

	public:

	static float gravity;
	static float dt_scale; // if time needs to be slowed down
	static World world;

	static void init();
};

#endif