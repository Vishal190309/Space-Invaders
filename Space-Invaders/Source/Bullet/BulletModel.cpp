#include "../../Header/Bullet/BulletModel.h"
namespace Bullet {
	BulletModel::BulletModel(BulletType type, Entity::EntityType ownerEntityType)
	{
		bulletType = type;
		this->ownerEntityType = ownerEntityType;
		
	}
	BulletModel::~BulletModel()
	{
	}
	void BulletModel::initialize(sf::Vector2f position, MovementDirection direction)
	{
		bulletPosition = position;
		movementDirection = direction;
	}
	sf::Vector2f BulletModel::getBulletPosition()
	{
		return bulletPosition;
	}
	void BulletModel::setBulletPosition(sf::Vector2f position)
	{
		bulletPosition = position;
	}
	BulletType BulletModel::getBulletType()
	{
		return bulletType;
	}
	void BulletModel::setBulletType(BulletType type)
	{
		bulletType = type;
	}
	MovementDirection BulletModel::getMovementDirection()
	{
		return movementDirection;
	}
	void BulletModel::setMovementDirection(MovementDirection direction)
	{
		movementDirection = direction;
	}
	float BulletModel::getMovementSpeed()
	{
		return bulletMovementSpeed;
	}
	void BulletModel::setMovementSpeed(float speed)
	{
		bulletMovementSpeed = speed;
	}
	Entity::EntityType BulletModel::getOwnerEntityType()
	{
		return ownerEntityType;
	}
}