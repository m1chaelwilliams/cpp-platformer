#ifndef SPHERE_APP_H
#define SPHERE_APP_H

#include <raylib.h>
#include "scenes/prelude.h"
#include <memory>

namespace chote {

	class App {

		public:

		std::shared_ptr<BaseScene> test_scene;

		App();
		~App();
		App(const App& other) = delete;

		void run();

		private:

		void loop();
		void quit();

		bool m_running;
	};

}

#endif