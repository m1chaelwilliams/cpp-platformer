// contains data for the entire world

#ifndef SPHERE_WORLD_H
#define SPRHERE_WORLD_H

#include "entities/entity.h"
#include <vector>
#include <memory>


class World {

	public:

	int level;
	std::vector<std::shared_ptr<Entity>> entities;
	Player player;

	World(int level);

};

#endif