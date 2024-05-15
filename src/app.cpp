#include "app.h"
#include "shareddata.h"

namespace chote {

	App::App() :
		m_running(true)
	{

		InitWindow(600, 400, "Platformer");

		#ifdef DEBUG
		SetExitKey(KEY_Q);
		#else
		SetExitKey(0);
		#endif

		SetTargetFPS(60);

	}

	App::~App() {

		CloseWindow();

	}

	void App::run() {

		SharedData::init();
		test_scene = std::make_shared<StartScene>();

		loop();
	}

	void App::loop() {
		while (!WindowShouldClose() && m_running) {
			
			test_scene->update();
			
			BeginDrawing();

			test_scene->draw();

			EndDrawing();
		}
	}

	void App::quit() {
		m_running = false;
	}

}