#pragma once
#include "MainMenu/MainMenuUIController.h"
#include "Gameplay/GameplayUIController.h"
#include "Interface\IUIController.h"


namespace UI {
	using namespace MainMenu;
	class UIService {
	private:

		MainMenu::MainMenuUIController* mainMenuUIController;
		GameplayUI::GameplayUIController* gameplayUIController;
		void createControllers();
		void initializeControllers();
		void destroy();
		Interface::IUIController* getCurrentUIController();
	public:
		UIService();
		~UIService();

		void initialize();
		void update();
		void render();
		void showUI();
			;
	};


}
