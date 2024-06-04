#include "../../Header/Enemy/Controllers/SubZeroController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../../Header/Bullet/BulletConfig.h"

namespace Enemy {
	namespace Controllers {
		void SubZeroController::move()
		{
			switch (enemyModel->getEnemyMovementDirection()) {
			case MovementDirection::DOWN:
				moveDown();
				break;
			}
			
		}
		void SubZeroController::moveDown()
		{
			sf::Vector2f currentPosition = enemyModel->getEnemyPosition();
			currentPosition.y += verticalMovmentSpeed * Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			enemyModel->setEnemyPosition(currentPosition);
		}

		void SubZeroController::fireBullet()
		{
			//Global::ServiceLocator::getInstance()->getBulletService()->spawnBullet(Bullet::BulletType::FROST_BULLET
			//	,enemyModel->getEnemyPosition()+ enemyModel->barrelPositionOffset
			//	,Bullet::MovementDirection::DOWN,enemyModel->getEntityType());
		}
		
		SubZeroController::SubZeroController(EnemyType type, Entity::EntityType entityType) : EnemyController(type,entityType)
		{
		}

		SubZeroController::~SubZeroController()
		{
		}
		void SubZeroController::initialize()
		{
			EnemyController::initialize();
			enemyModel->setEnemyMovementDirection(MovementDirection::DOWN);
			rateOfFire = subZeroFireRate;
		}
	}
}