#include "../../Header/Enemy/Controllers/ThunderSnakeController.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../../Header/Bullet/BulletConfig.h"

namespace Enemy {
	namespace Controllers {
		void ThunderSnakeController::move()
		{
			switch (enemyModel->getEnemyMovementDirection())
			{
			case MovementDirection::LEFT:
				moveLeft();
				break;
			case MovementDirection::RIGHT:
				moveRight();
				break;
			}
		}
		void ThunderSnakeController::moveLeft()
		{
			sf::Vector2f currentPosition = enemyModel->getEnemyPosition();
			currentPosition.x -= horizontalMovementSpeed * Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
			currentPosition.y += verticalMovmentSpeed * Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
			if (currentPosition.x <= enemyModel->leftMostPosition.x) {
				enemyModel->setEnemyMovementDirection(MovementDirection::RIGHT);
			}
			else {
				enemyModel->setEnemyPosition(currentPosition);
			}
		}
		void ThunderSnakeController::moveRight()
		{
			sf::Vector2f currentPosition = enemyModel->getEnemyPosition();
			currentPosition.x += horizontalMovementSpeed * Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
			currentPosition.y += verticalMovmentSpeed * Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
			if (currentPosition.x >= enemyModel->rightMostPosition.x) {
				enemyModel->setEnemyMovementDirection(MovementDirection::LEFT);
			}
			else {
				enemyModel->setEnemyPosition(currentPosition);
			}
		}
		void ThunderSnakeController::fireBullet()
		{
			Global::ServiceLocator::getInstance()->getBulletService()->spawnBullet(Bullet::BulletType::TORPEDO
				, enemyModel->getEnemyPosition() + enemyModel->barrelPositionOffset
				, Bullet::MovementDirection::DOWN,enemyModel->getEntityType());
		
		}
		ThunderSnakeController::ThunderSnakeController(EnemyType type, Entity::EntityType entityType):EnemyController(type,entityType)
		{
		}
		ThunderSnakeController::~ThunderSnakeController()
		{
		}
		void ThunderSnakeController::initialize()
		{
			EnemyController::initialize();
			rateOfFire = thunderSnakeFireRate;
		}
	}
}