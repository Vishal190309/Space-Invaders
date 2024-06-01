#include "../../Header/Main/GameService.h"
#include "../../Header/UI/UIService.h"
#include "../../Header/UI/UIElement/TextView.h"




namespace UI {
	using namespace Main;
	using namespace MainMenu;
	using namespace Interface;
	using namespace UIElement;
	void UIService::createControllers()
	{
		mainMenuController = new MainMenuUIController();
	}

	void UIService::initializeControllers()
	{
		mainMenuController->initialize();
	}

	void UIService::destroy()
	{
		delete(mainMenuController);
	}

	Interface::IUIController* UIService::getCurrentUIController()
	{
		switch (GameService::getGameState()) {
		case GameState::MAIN_MENU:
			return mainMenuController;
			break;
		default:
			return nullptr;
		}
	}

	UIService::UIService()
	{
		mainMenuController = nullptr;
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
