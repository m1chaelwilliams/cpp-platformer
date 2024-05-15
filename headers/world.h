// contains data for the entire world

#ifndef WORLD_H
#define WORLD_H

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