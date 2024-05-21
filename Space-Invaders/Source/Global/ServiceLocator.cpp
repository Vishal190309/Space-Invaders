#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Main/GameService.h"
namespace Global {
	using namespace Main;
	using namespace Player;
	
	ServiceLocator::ServiceLocator()
	{
		graphicService = nullptr;
		eventService = nullptr;
		gameplayService = nullptr;
		playerService = nullptr;
		enemyService = nullptr;
		timeService = nullptr;
		uiService = nullptr;
		
		createServices();
	}

	ServiceLocator::~ServiceLocator()
	{
		clearAllServices();
	}

	void ServiceLocator::createServices()
	{
		graphicService = new GraphicService();
		eventService = new Event::EventService();
		gameplayService = new GameplayService();
		playerService = new PlayerService();
		enemyService = new EnemyService();
		timeService = new TimeService();
		uiService = new UIService();
		
;	}

	void ServiceLocator::clearAllServices()
	{
		delete(graphicService);
		delete(eventService);
		delete(gameplayService);
		delete(playerService);
		delete(enemyService);
		delete(timeService);
		delete(uiService);
	}

	ServiceLocator* ServiceLocator::getInstance()
	{
		static ServiceLocator instance;
		return &instance;
	}

	void ServiceLocator::initialize()
	{
		graphicService->initialize();
		eventService->initialize();
		gameplayService->initialize();
		playerService->initialize();
		enemyService->initialize();
		timeService->initialize();
		uiService->initialize();
	}

	void ServiceLocator::update()
	{
		graphicService->update();
		eventService->update();
		if (GameService::getGameState() == GameState::GAMEPLAY) {
			gameplayService->update();
			playerService->update();
			enemyService->update();
		}
		timeService->update();
		uiService->update();
	}

	void ServiceLocator::render()
	{
		graphicService->render();
		if (GameService::getGameState() == GameState::GAMEPLAY) {
			gameplayService->render();
			playerService->render();
			enemyService->render();
		}
		uiService->render();
		

	}

	Event::EventService* ServiceLocator::getEventService()
	{
		return eventService;
	}

	GraphicService* ServiceLocator::getGraphicService()
	{
		return graphicService;
	}

	PlayerService* ServiceLocator::getPlayerService()
	{
		return playerService;
	}

	EnemyService* ServiceLocator::getEnemyService()
	{
		return enemyService;
	}

	TimeService* ServiceLocator::getTimeService()
	{
		return timeService;
	}
	UIService* ServiceLocator::getUIService()
	{
		return uiService;
	}
	GameplayService* ServiceLocator::getGameplayService()
	{
		return gameplayService;
	}
}