#include "../Header/PlayerService.h"
#include "../Header/ServiceLocator.h"

void PlayerService::initializePlayerSprite()
{
	if (playerTexture.loadFromFile(texturePath)) {
		playerSprite.setTexture(playerTexture);
	}
}

void PlayerService::ProcessPlayerInput()
{
	eventService = ServiceLocator::getInstance()->getEventService();
	if (eventService->isKeyboardEvent()) {
		if (eventService->pressedLeftKey()) {
			moveLeft();
		}

		if (eventService->pressedRightKey()) {
			moveRight();
		}
	}
}

void PlayerService::moveLeft()
{
	position.x += -movementSpeed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();;
}

void PlayerService::moveRight()
{
	position.x +=  movementSpeed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();;
}

PlayerService::PlayerService()
{
	gameWindow = nullptr;
	eventService = nullptr;
}

PlayerService::~PlayerService() = default;


void PlayerService::initialize()
{
	gameWindow = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
	initializePlayerSprite();
}

void PlayerService::update()
{
	ProcessPlayerInput();
	playerSprite.setPosition(position);
}

void PlayerService::render()
{
	gameWindow->draw(playerSprite);
}

int PlayerService::getMoveSpeed()
{
	return movementSpeed;
}

sf::Vector2f PlayerService::getPosition()
{
	return position;
}


