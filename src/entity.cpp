#include "entities/entity.h"

Entity::Entity(
	const Sprite& sprite
) :
	sprite(sprite),
	alive(true)
{}

void Entity::update() {

}

void Entity::draw() {
	DrawTexturePro(
		sprite.texture,
		sprite.drect,
		sprite.srect,
		sprite.origin,
		sprite.rotation,
		sprite.tint
	);
}

// --- PhysicsEntity ---

PhysicsEntity::PhysicsEntity(
	const Sprite& sprite,
	const Physics& physics
) :
	Entity(sprite),
	physics(physics)
{}

void PhysicsEntity::move_x() {
	float translation = physics.velocity.x * physics.speed;

	sprite.drect.x += translation;
	physics.hitbox.x += translation;
}

void PhysicsEntity::move_y() {
	float translation = physics.velocity.y * physics.gravity_scale;

	sprite.drect.y += translation;
	physics.hitbox.y += translation;
}

void PhysicsEntity::draw() {
	Entity::draw();
}

void PhysicsEntity::update() {
	Entity::update();
}

// --- Player ---

Player::Player(
	const Sprite& sprite,
	const Physics& physics,
	const PlatformerController& controller
) :
	PhysicsEntity(
		sprite,
		physics
	),
	controller(controller)
{}

void Player::draw() {
	DrawRectangle(
		0,0,100,100,RED
	);
}

void Player::update() {
	controller.update();

	physics.velocity.x = 0.0f;
	
	if (controller.right) {
		physics.velocity.x = 1.0f;
	}
	if (controller.left) {
		physics.velocity.x = -1.0f;
	}
}