#ifndef SPHERE_ENTITY_H
#define SPHERE_ENTITY_H

#include <raylib.h>
#include "components/prelude.h"

class Entity {

	public:
	
	bool alive;
	Sprite sprite;

	Entity() {
		sprite = (Sprite) {
			.texture = Texture{},
			.drect = Rectangle{},
			.srect = Rectangle{},
			.origin = Vector2{},
			.rotation = 0.0f,
			.tint = RAYWHITE
		};
	}

	Entity(
		const Sprite& sprite
	);
	
	virtual ~Entity() = default;
	Entity(const Entity& other) = default;

	virtual void draw();
	virtual void update();

};

class PhysicsEntity : public Entity {
	public:

	Physics physics;

	PhysicsEntity() :
		Entity()
	{
		physics = (Physics){
			.solid = true,
			.velocity = Vector2{},			
			.speed = 1.0f,
			.gravity_scale = 1.0f,
			.hitbox = Rectangle{},
		};
	}

	PhysicsEntity(
		const Sprite& sprite,
		const Physics& physics
	);

	virtual void update();
	virtual void draw();
	virtual void move_x();
	virtual void move_y();
};

class Player : PhysicsEntity {
	public:

	PlatformerController controller;

	Player() :
		PhysicsEntity(),
		controller(
			PlatformerController(
				KEY_LEFT,
				KEY_RIGHT,
				KEY_SPACE
			)
		)
	{}

	Player(
		const Sprite& sprite,
		const Physics& physics,
		const PlatformerController& controller
	);

	virtual void update();
	virtual void draw();
};

#endif