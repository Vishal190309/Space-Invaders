#include "../../Header/Powerups/PowerupController.h"
#include "../../Header/Powerups/PowerupConfig.h"
#include "../../Header/Powerups/PowerupModel.h"
#include "../../Header/Powerups/PowerupView.h"
#include "../../header/Global/ServiceLocator.h"

namespace Powerup {

	void PowerupController::updatePowerupPosition()
	{
		sf::Vector2f currentPosition = getPowerupPosition();
		currentPosition.y += powerupModel->getMovementSpeed() * Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
		powerupModel->setPowerupPosition(currentPosition);
	}
	void PowerupController::handleOutOfBounds()
	{
		sf::Vector2f currentPosition = getPowerupPosition();
		sf::Vector2u windowSize = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->getSize();
		if (currentPosition.x<0 || currentPosition.x > windowSize.x ||
			currentPosition.y <0 || currentPosition.y> windowSize.y) {
			Global::ServiceLocator::getInstance()->getPowerupService()->destroyPowerup(this);
		}
	}
	PowerupController::PowerupController(PowerupType type)
	{
		powerupModel = new PowerupModel(type);
		powerupView = new PowerupView();
	}
	PowerupController::~PowerupController()
	{
		delete(powerupModel);
		delete(powerupView);
	}
	void PowerupController::initialize(sf::Vector2f position)
	{
		powerupModel->initialize(position);
		powerupView->initialize(this);
	}
	void PowerupController::update()
	{
		updatePowerupPosition();
		powerupView->update();
	}
	void PowerupController::render()
	{
		powerupView->render();
	}
	void PowerupController::onCollected()
	{
	}
	sf::Vector2f PowerupController::getPowerupPosition()
	{
		return powerupModel->getPowerupPosition();
	}
	PowerupType PowerupController::getPowerupType()
	{
		return powerupModel->getPowerupType();
	}
}