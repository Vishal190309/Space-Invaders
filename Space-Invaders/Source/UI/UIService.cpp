#include "../../Header/Main/GameService.h"
#include "../../Header/UI/UIService.h"
#include "../../Header/UI/UIElement/TextView.h"




namespace UI {
	using namespace Main;
	using namespace MainMenu;
	using namespace GameplayUI;
	using namespace Interface;
	using namespace UIElement;
	void UIService::createControllers()
	{
		mainMenuUIController = new MainMenuUIController();
		gameplayUIController = new GameplayUIController();
	}

	void UIService::initializeControllers()
	{
		mainMenuUIController->initialize();
		gameplayUIController->initialize();
	}

	void UIService::destroy()
	{
		delete(mainMenuUIController);
		delete(gameplayUIController);
	}

	Interface::IUIController* UIService::getCurrentUIController()
	{
		switch (GameService::getGameState()) {
		case GameState::MAIN_MENU:
			return mainMenuUIController;
			break;
		case GameState::GAMEPLAY:
			return gameplayUIController;
		default:
			return nullptr;
		}
	}

	UIService::UIService()
	{
		mainMenuUIController = nullptr;
		gameplayUIController = nullptr;
		createControllers();
	}

	UIService::~UIService()
	{
		destroy();
	}

	void UIService::initialize()
	{
		TextView::initializeTextView();
		initializeControllers();
		
	}

	void UIService::update()
	{
		IUIController* uiController = getCurrentUIController();
		if (uiController) uiController->update();
		
	}

	void UIService::render()
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
