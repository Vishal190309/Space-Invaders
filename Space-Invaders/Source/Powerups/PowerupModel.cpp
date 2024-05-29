#include "../../Header/Powerups/PowerupModel.h"
#include "../../Header/Powerups/PowerupConfig.h"

namespace Powerup {
	PowerupModel::PowerupModel(PowerupType type)
	{
		powerupType = type;
	}
	PowerupModel::~PowerupModel()
	{
	}
	void PowerupModel::initialize(sf::Vector2f position)
	{
		powerupPosition = position;
	}
	sf::Vector2f PowerupModel::getPowerupPosition()
	{
		return powerupPosition;
	}
	void PowerupModel::setPowerupPosition(sf::Vector2f position)
	{
		powerupPosition = position;
	}
	PowerupType PowerupModel::getPowerupType()
	{
		return powerupType;
	}
	void PowerupModel::setPowerupType(PowerupType type)
	{
		powerupType = type;
	}
	float PowerupModel::getMovementSpeed()
	{
		return movementSpeed;
	}
	void PowerupModel::setMovementSpeed(float movementSpeed)
	{
		this->movementSpeed = movementSpeed;
	}
}