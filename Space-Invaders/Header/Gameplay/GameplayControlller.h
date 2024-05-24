#pragma once

namespace Gameplay {
	class GameplayView;
	class GameplayController {
	private:
		GameplayView* gameplayView;
		void destroy();
	public:
		GameplayController();
		~GameplayController();

		void initialize();
		void update();
		void render();

	};
}