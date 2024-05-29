#include "../../Header/Main/GameService.h"
#include "../../Header/UI/UIService.h"

namespace UI {
	using namespace Main;
	using namespace MainMenu;
	using namespace Interface;
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

	Interface::IUIController* UIService::getCurrentUIController()
	{
		switch (GameService::getGameState()) {
		case GameState::MAIN_MENU:
			return new MainMenuUIController();
			break;
		default:
			return nullptr;
		}
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
		IUIController* uiController = getCurrentUIController();
		if (uiController) uiController->update();
		
	}

	void UI::UIService::render()
	{
		IUIController* uiController = getCurrentUIController();
		if (uiController) uiController->render();
	}
	void UIService::showUI()
	{
		IUIController* uiController = getCurrentUIController();
		if (uiController) uiController->show();
	}
}
