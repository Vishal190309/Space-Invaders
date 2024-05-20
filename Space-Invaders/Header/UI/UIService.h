#pragma once
#include "MainMenu/MainMenuUIController.h"


namespace UI {
	using namespace MainMenu;
	class UIService {
	private:

		MainMenu::MainMenuUIController* mainMenuController;
		void createControllers();
		void initializeControllers();
		void destroy();

	public:
		UIService();
		~UIService();

		void initialize();
		void update();
		void render()
			;
	};


}
