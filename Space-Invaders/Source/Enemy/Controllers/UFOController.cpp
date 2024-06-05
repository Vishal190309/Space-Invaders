#include "../../../Header/Enemy/Controllers/UFOController.h"
#include "../../../Header/Enemy/EnemyConfig.h"
#include "../../../Header/Enemy/EnemyModel.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Bullet/BulletController.h"


namespace Enemy {
	namespace Controllers {


		void UFOController::move()
		{
			switch (enemyModel->getEnemyMovementDirection()) {
			case MovementDirection::LEFT:
				moveLeft();
				break;
			case MovementDirection::RIGHT:
				moveRight();
				break;
			}
		}

		void UFOController::moveLeft()
		{
			sf::Vector2f currentPosition = enemyModel->getEnemyPosition();
			currentPosition.x -= (enemyModel->enemyMovementSpeed * Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime());
			if (currentPosition.x < enemyModel->leftMostPosition.x) {
				enemyModel->setReferencePosition(currentPosition);
				enemyModel->setEnemyMovementDirection(MovementDirection::RIGHT);
			}
			else {
				enemyModel->setEnemyPosition(currentPosition);
			}
		}

		void UFOController::moveRight()
		{
			sf::Vector2f currentPosition = enemyModel->getEnemyPosition();
			currentPosition.x += (enemyModel->enemyMovementSpeed * Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime());
			if (currentPosition.x > enemyModel->rightMostPosition.x) {
				enemyModel->setReferencePosition(currentPosition);
				enemyModel->setEnemyMovementDirection(MovementDirection::LEFT);
			}
			else {
				enemyModel->setEnemyPosition(currentPosition);
			}
		}

		void UFOController::fireBullet()
		{
		}

		Powerup::PowerupType UFOController::getRandomPowerupType()
		{
			std::srand(static_cast<unsigned int>(std::time(nullptr)));

			//We add '1'  to OutscalBomb below because enum has a 0 index, making the bomb number 3, we need to add 1 to make it 4 

			int random_value = std::rand() % (static_cast<int>(Powerup::PowerupType::OUTSCAL_BOMB) + 1);
			return static_cast<Powerup::PowerupType>(random_value);
		}

		UFOController::UFOController(EnemyType type, Entity::EntityType entityType) :EnemyController(type,entityType)
		{
		}

		UFOController::~UFOController()
		{
		}

		void UFOController::initialize()
		{
			EnemyController::initialize();
		}

		void UFOController::onCollision(ICollider* otherCollider)
		{
			Bullet::BulletController* bulletController = dynamic_cast<Bullet::BulletController*>(otherCollider);
			if (bulletController) {
				Global::ServiceLocator::getInstance()->getPowerupService()->spawnPowerup(getRandomPowerupType(), enemyModel->getEnemyPosition());
				destroy();
				return;
			}
		}

	}
}
