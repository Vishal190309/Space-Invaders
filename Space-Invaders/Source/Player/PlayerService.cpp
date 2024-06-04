#include "../../Header/Player/PlayerService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Player/PlayerController.h"

namespace Player {

	PlayerService::PlayerService()
	{
		playerController = new PlayerController(Entity::EntityType::PLAYER);
	}

	PlayerService::~PlayerService() {
		delete (playerController);
	}


	void PlayerService::initialize()
	{
		playerController->initialize();
	}

	void PlayerService::update()
	{
		playerController->update();
	}

	void PlayerService::render()
	{
		playerController->render();
	}
	void PlayerService::enableShield()
	{
		playerController->enableShield();
	}
	void PlayerService::enableRapidFire()
	{
		playerController->enableRapidFire();
	}
	void PlayerService::enableTrippleLaser()
	{
		playerController->enableTrippleLaser();
	}
	void PlayerService::increaseEnemiesKilled(int val)
	{
		playerController->increaseEnemiesKilled(val);
	}
	void PlayerService::reset()
	{
		playerController->reset();
	}
}

