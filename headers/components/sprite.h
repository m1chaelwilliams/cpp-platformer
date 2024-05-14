#ifndef SPRITE_H
#define SPRITE_H

#include <raylib.h>

struct Sprite {
	Texture2D texture;
	Rectangle drect;
	Rectangle srect;
	Vector2 origin;
	float rotation;
	Color tint;
};

#endif