#include "../../../Header/Enemy/Controllers/ZapperController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Global/ServiceLocator.h"
namespace Enemy {
	namespace Controllers {
		void ZapperController::move()
		{
			switch (enemyModel->getEnemyMovementDirection()) {
			case MovementDirection::LEFT:
				moveLeft();
				break;
			case MovementDirection::RIGHT:
				moveRight();
				break;
			case MovementDirection::DOWN:
				moveDown();
				break;
			}
		}
		void ZapperController::moveLeft()
		{
			sf::Vector2f currentPosition = enemyModel->getEnemyPosition();
			currentPosition.x -= (enemyModel->enemyMovementSpeed * Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime());
			if (currentPosition.x < enemyModel->leftMostPosition.x) {
				enemyModel->setReferencePosition(currentPosition);
				enemyModel->setEnemyMovementDirection(MovementDirection::DOWN);
			}
			else {
				enemyModel->setEnemyPosition(currentPosition);
			}
		}
		void ZapperController::moveRight()
		{
			sf::Vector2f currentPosition = enemyModel->getEnemyPosition();
			currentPosition.x += (enemyModel->enemyMovementSpeed * Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime());
			if (currentPosition.x > enemyModel->rightMostPosition.x) {
				enemyModel->setReferencePosition(currentPosition);
				enemyModel->setEnemyMovementDirection(MovementDirection::DOWN);
			}
			else {
				enemyModel->setEnemyPosition(currentPosition);
			}
		}
		void ZapperController::moveDown()
		{
			sf::Vector2f currentPosition = enemyModel->getEnemyPosition();
			currentPosition.y += (enemyModel->enemyMovementSpeed * Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime());
			if (currentPosition.y > enemyModel->getReferencePosition().y + enemyModel->DownMoveDistance) {
				if (enemyModel->getReferencePosition().x <= enemyModel->leftMostPosition.x) {
					enemyModel->setEnemyMovementDirection(MovementDirection::RIGHT);
				}
				else if (enemyModel->getReferencePosition().x >= enemyModel->rightMostPosition.x) {
					enemyModel->setEnemyMovementDirection(MovementDirection::LEFT);
				}

			}
			else {
				enemyModel->setEnemyPosition(currentPosition);
			}
		}
		void ZapperController::fireBullet()
		{
			//Global::ServiceLocator::getInstance()->getBulletService()->spawnBullet(Bullet::BulletType::LASER_BULLET
			//	, enemyModel->getEnemyPosition() + enemyModel->barrelPositionOffset
			//	, Bullet::MovementDirection::DOWN,enemyModel->getEntityType());
		}
		ZapperController::ZapperController(EnemyType type, Entity::EntityType entityType) : EnemyController(type,entityType)
		{
		}
		ZapperController::~ZapperController()
		{
		}
		void ZapperController::initialize()
		{
			EnemyController::initialize();
			rateOfFire = zapperFireRate;
		}
	}
}