#include "../../Header/Player/PlayerController.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Player/PlayerModel.h"
#include "../../Header/Player/PlayerView.h"

#include<algorithm>

namespace Player {
	PlayerController::PlayerController()
	{
		playerView = new PlayerView();
		playerModel = new PlayerModel();

	}

	PlayerController::~PlayerController()
	{
		delete(playerModel);
		delete(playerView);
	}

	void PlayerController::initialize()
	{
		playerModel->initialize();
		playerView->initialize(this);
	}

	void PlayerController::update()
	{
		processPlayerInput();
		playerView->update();
	}

	void PlayerController::render()
	{
		playerView->render();
	}

	sf::Vector2f PlayerController::getPlayerPosition()
	{
		return playerModel->getPlayerPosition();
	}

	void PlayerController::processPlayerInput()
	{
		Event::EventService* eventService = Global::ServiceLocator::getInstance()->getEventService();
		// we will move this to event service at a later time
		if (eventService->pressedAKey() || eventService->pressedLeftKey())
		{
			moveLeft();
		}
		// we will move this to event service at a later time
		if (eventService->pressedDKey() || eventService->pressedRightKey())
		{
			moveRight();
		}
	}

	void PlayerController::moveLeft()
	{
		sf::Vector2f currentPosition = playerModel->getPlayerPosition();
		currentPosition.x -= playerModel->playerMovementSpeed * Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		currentPosition.x = std::max(currentPosition.x, playerModel->leftMostPosition.x);
		playerModel->setPlayerPosition(currentPosition);
	}

	void PlayerController::moveRight()
	{
		sf::Vector2f currentPosition = playerModel->getPlayerPosition();
		currentPosition.x += playerModel->playerMovementSpeed * Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		currentPosition.x = std::min(currentPosition.x, playerModel->rightMostPosition.x);
		playerModel->setPlayerPosition(currentPosition);
	}

}

