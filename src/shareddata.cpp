#include "shareddata.h"

float SharedData::gravity;
float SharedData::dt_scale;
World SharedData::world(1);

void SharedData::init() {
	SharedData::gravity = 1.0f;
	SharedData::dt_scale = 1.0f;
	SharedData::world = World(1);
}