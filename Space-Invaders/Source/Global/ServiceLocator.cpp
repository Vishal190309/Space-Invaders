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
		elementService = nullptr;
		enemyService = nullptr;
		bulletService = nullptr;
		powerupService = nullptr;
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
		elementService = new ElementService();
		enemyService = new EnemyService();
		bulletService = new BulletService();
		powerupService = new PowerupService();
		timeService = new TimeService();
		uiService = new UIService();
		soundService = new SoundService();
		
;	}

	void ServiceLocator::clearAllServices()
	{
		delete(graphicService);
		delete(eventService);
		delete(gameplayService);
		delete(playerService);
		delete(elementService);
		delete(enemyService);
		delete(bulletService);
		delete(powerupService);
		delete(timeService);
		delete(uiService);
		delete(soundService);
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
		elementService->initialize();
		enemyService->initialize();
		bulletService->initialize();
		powerupService->initialize();
		timeService->initialize();
		uiService->initialize();
		soundService->initialize();
	}

	void ServiceLocator::update()
	{
		graphicService->update();
		eventService->update();
		if (GameService::getGameState() == GameState::GAMEPLAY) {
			gameplayService->update();
			playerService->update();
			elementService->update();
			enemyService->update();
			bulletService->update();
			powerupService->update();
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
			elementService->render();
			enemyService->render();
			bulletService->render();
			powerupService->render();
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

	ElementService* ServiceLocator::getElementService()
	{
		return elementService;
	}

	EnemyService* ServiceLocator::getEnemyService()
	{
		return enemyService;
	}

	BulletService* ServiceLocator::getBulletService()
	{
		return bulletService;
	}

	PowerupService* ServiceLocator::getPowerupService()
	{
		return powerupService;
	}

	TimeService* ServiceLocator::getTimeService()
	{
		return timeService;
	}
	UIService* ServiceLocator::getUIService()
	{
		return uiService;
	}
	SoundService* ServiceLocator::getSoundService()
	{
		return soundService;
	}
	GameplayService* ServiceLocator::getGameplayService()
	{
		return gameplayService;
	}
}