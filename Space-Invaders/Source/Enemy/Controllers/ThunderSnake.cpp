#include "../../Header/Enemy/Controllers/ThunderSnakeController.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Global/ServiceLocator.h"

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
		ThunderSnakeController::ThunderSnakeController(EnemyType type):EnemyController(type)
		{
		}
		ThunderSnakeController::~ThunderSnakeController()
		{
		}
		void ThunderSnakeController::initialize()
		{
			EnemyController::initialize();
		}
	}
}