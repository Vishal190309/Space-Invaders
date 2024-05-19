#include "../Header/PlayerService.h"
#include "../Header/ServiceLocator.h"




PlayerService::PlayerService()
{
	playerController = new PlayerController();
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


