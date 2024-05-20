#include "../../Header/Enemy/EnemyModel.h"
namespace Enemy {
	EnemyModel::EnemyModel()
	{
		enemyPosition = referencePosition;
		enemyMovementDirection = MovementDirection::Right;
	}
	EnemyModel::~EnemyModel()
	{
	}
	void EnemyModel::initialize()
	{
	}
	void EnemyModel::reset()
	{
	}
	sf::Vector2f EnemyModel::getEnemyPosition()
	{
		return enemyPosition;
	}
	void EnemyModel::setEnemyPosition(sf::Vector2f position)
	{
		enemyPosition = position;
	}
	sf::Vector2f EnemyModel::getReferencePosition()
	{
		return referencePosition;
	}
	void EnemyModel::setReferencePosition(sf::Vector2f position)
	{
		referencePosition = position;
	}
	MovementDirection EnemyModel::getEnemyMovementDirection()
	{
		return enemyMovementDirection;
	}
	void EnemyModel::setEnemyMovementDirection(MovementDirection newMovementDirection)
	{
		enemyMovementDirection = newMovementDirection;
	}
}