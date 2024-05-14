// lightweight physics component for physics entities

#ifndef PHYSICS_H
#define PHYSICS_H

#include <raylib.h>

struct Physics {
	bool solid;
	Vector2 velocity;
	float speed;
	float gravity_scale;
	Rectangle hitbox;
};

#endif