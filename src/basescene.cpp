#include "scenes/basescene.h"
#include "shareddata.h"

BaseScene::BaseScene(int uid) :
	uid(uid),
	loaded(false)
{}

void BaseScene::update() {
	SharedData::world.player.update();
}
void BaseScene::draw() {
	SharedData::world.player.draw();
}
void BaseScene::enter(int sender_uid) {}
void BaseScene::exit() {}
void BaseScene::first_load() {}