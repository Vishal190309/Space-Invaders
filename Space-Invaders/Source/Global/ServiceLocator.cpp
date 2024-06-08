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
		animationService = nullptr;
		playerService = nullptr;
		elementService = nullptr;
		enemyService = nullptr;
		bulletService = nullptr;
		powerupService = nullptr;
		timeService = nullptr;
		uiService = nullptr;
		collisionService = nullptr;
		
		createServices();
	}

	ServiceLocator::~ServiceLocator()
	{
		clearAllServices();
	}

	void ServiceLocator::createServices()
	{
		graphicService = new GraphicService();
		timeService = new TimeService();
		eventService = new Event::EventService();
		gameplayService = new GameplayService();
		animationService = new AnimationService();
		playerService = new PlayerService();
		elementService = new ElementService();
		enemyService = new EnemyService();
		bulletService = new BulletService();
		powerupService = new PowerupService();
		
		uiService = new UIService();
		soundService = new SoundService();
		collisionService = new CollisionService();
		
;	}

	void ServiceLocator::clearAllServices()
	{
		delete(graphicService);
		delete(timeService);
		delete(eventService);
		delete(gameplayService);
		delete(animationService);
		delete(playerService);
		delete(elementService);
		delete(enemyService);
		delete(bulletService);
		delete(powerupService);
		
		delete(uiService);
		delete(soundService);
		delete(collisionService);
	}

	ServiceLocator* ServiceLocator::getInstance()
	{
		static ServiceLocator instance;
		return &instance;
	}
	
	void ServiceLocator::initialize()
	{
		graphicService->initialize();
		timeService->initialize();
		eventService->initialize();
		gameplayService->initialize();
		animationService->initialize();
		playerService->initialize();
		elementService->initialize();
		enemyService->initialize();
		bulletService->initialize();
		powerupService->initialize();
		uiService->initialize();
		soundService->initialize();
		collisionService->initialize();
	}

	void ServiceLocator::update()
	{
		graphicService->update();
		timeService->update();
		eventService->update();

		if (GameService::getGameState() == GameState::GAMEPLAY) {
			gameplayService->update();
			animationService->update();
			playerService->update();
			elementService->update();
			enemyService->update();
			bulletService->update();
			powerupService->update();
			collisionService->update();
		}
		
		uiService->update();
	}

	void ServiceLocator::render()
	{
		graphicService->render();
		if (GameService::getGameState() == GameState::GAMEPLAY) {
			gameplayService->render();
			animationService->render();
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
	CollisionService* ServiceLocator::getCollisionService()
	{
		return collisionService;
	}
	GameplayService* ServiceLocator::getGameplayService()
	{
		return gameplayService;
	}
	AnimationService* ServiceLocator::getAnimationService()
	{
		return animationService;
	}
}