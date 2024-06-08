#pragma once
#include "MainMenu/MainMenuUIController.h"
#include "Gameplay/GameplayUIController.h"
#include "Interface/IUIController.h"
#include"SplashScreenUI/SplashScreenUIController.h"


namespace UI {
	using namespace MainMenu;
	using namespace SplashScreenUI;
	class UIService {
	private:
		SplashScreenUIController* splashScreenUIController;
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
			
	};


}
