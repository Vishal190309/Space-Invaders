#include "../../Header/Main/GameService.h"
#include "../../Header/UI/UIService.h"

namespace UI {
	using namespace Main;
	using namespace MainMenu;
	void UI::UIService::createControllers()
	{
		mainMenuController = new MainMenuUIController();
	}

	void UI::UIService::initializeControllers()
	{
		mainMenuController->initialize();
	}

	void UI::UIService::destroy()
	{
		delete(mainMenuController);
	}

	UI::UIService::UIService()
	{
		mainMenuController = nullptr;
		createControllers();
	}

	UI::UIService::~UIService()
	{
		destroy();
	}

	void UI::UIService::initialize()
	{

		initializeControllers();
	}

	void UI::UIService::update()
	{
		switch (GameService::getGameState()) {
		case GameState::MAIN_MENU:
			return mainMenuController->update();
			break;

		}
		
	}

	void UI::UIService::render()
	{
		switch (GameService::getGameState()) {
		case GameState::MAIN_MENU:
			return mainMenuController->render();
			break;

		}
	}
}
