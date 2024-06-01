#include "../../Header/Gameplay/GameplayService.h"
#include "../../Header/Gameplay/GameplayControlller.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Gameplay {
	GameplayService::GameplayService()
	{
		gameplayController = new GameplayController();
	}
	GameplayService::~GameplayService()
	{
		delete(gameplayController);
	}
	void GameplayService::initialize()
	{
		gameplayController->initialize();
	}
	void GameplayService::update()
	{
		gameplayController->update();
	}
	void GameplayService::render()
	{
		gameplayController->render();
	}
	void GameplayService::restart()
	{
		Global::ServiceLocator::getInstance()->getPlayerService()->reset();
		Global::ServiceLocator::getInstance()->getEnemyService()->reset();
		Global::ServiceLocator::getInstance()->getBulletService()->reset();
		Global::ServiceLocator::getInstance()->getElementService()->reset();
	}
}