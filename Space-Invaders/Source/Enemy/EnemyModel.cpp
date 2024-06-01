#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"
namespace Enemy {
	EnemyModel::EnemyModel(EnemyType Type, Entity::EntityType entityType)
	{
		enemyType = Type;
		this->entityType = entityType;
		
	}
	EnemyModel::~EnemyModel()
	{
	
	}
	void EnemyModel::initialize()
	{
		enemyState = EnemyState::PATROLLING;
		enemyPosition = referencePosition ;
		enemyMovementDirection = MovementDirection::RIGHT;
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
	EnemyType EnemyModel::getEnemyType()
	{
		return enemyType;
	}
	void EnemyModel::setEnemyType(EnemyType Type)
	{
		enemyType = Type;
	}
	EnemyState EnemyModel::getEnemyState()
	{
		return enemyState;
	}
	void EnemyModel::setEnemyState(EnemyState State)
	{
		enemyState = State;
	}
	Entity::EntityType EnemyModel::getEntityType()
	{
		return entityType;
	}
}