#ifndef BASESCENE_H
#define BASESCENE_H

class BaseScene {

	public:

	bool loaded;
	int uid; // enum unique id
	
	BaseScene(
		int uid
	);
	virtual ~BaseScene() = default;
	BaseScene(const BaseScene& other) = default;

	virtual void first_load();
	virtual void enter(int sender_uid);
	virtual void exit();
	virtual void update();
	virtual void draw();

};

#endif