#include "../../Header/Gameplay/GameplayControlller.h"
#include "../../Header/Gameplay/GameplayView.h"

namespace Gameplay {
	void GameplayController::destroy()
	{
		delete(gameplayView);
	}
	GameplayController::GameplayController()
	{
		gameplayView = new GameplayView();
	}
	GameplayController::~GameplayController()
	{
		destroy();
	}
	void GameplayController::initialize()
	{
		gameplayView->initialize();
	}
	void GameplayController::update()
	{
		gameplayView->update();
	}
	void GameplayController::render()
	{
		gameplayView->render();
	}
}