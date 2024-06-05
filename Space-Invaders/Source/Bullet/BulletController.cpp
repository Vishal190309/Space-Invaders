#include "../../Header/Bullet/BulletController.h"
#include "../../Header/Bullet/BulletModel.h"
#include "../../Header/Bullet/BulletView.h"
#include "../../Header/Bullet/BulletConfig.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Player/PlayerController.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Element/Bunker/BunkerController.h"
#include "../../Header/Entity/EntityConfig.h"


namespace Bullet {
	void BulletController::updateProjectilePosition()
	{
		switch (bulletModel->getMovementDirection())
		{
		case MovementDirection::UP:
			moveUp();
			break;
		case MovementDirection::DOWN:
			moveDown();
			break;
		
		}
	}
	void BulletController::processBulletCollision(ICollider* otherCollider)
	{
		BulletController* bulletController = dynamic_cast<BulletController*>(otherCollider);
		if (bulletController) {
			Global::ServiceLocator::getInstance()->getBulletService()->destroyBullet(this);
		}
	}
	void BulletController::processEnemyCollision(ICollider* otherCollider)
	{
		Enemy::EnemyController* enemyController = dynamic_cast<Enemy::EnemyController*>(otherCollider);
		if (enemyController && getOwnerEntityType()!= Entity::EntityType::ENEMY) {
			Global::ServiceLocator::getInstance()->getBulletService()->destroyBullet(this);
		}
	}
	void BulletController::processPlayerCollision(ICollider* otherCollider)
	{
		Player::PlayerController* palyerController = dynamic_cast<Player::PlayerController*>(otherCollider);
		if (palyerController && getOwnerEntityType() != Entity::EntityType::PLAYER) {
			Global::ServiceLocator::getInstance()->getBulletService()->destroyBullet(this);
		}
	}
	void BulletController::processBunkerCollision(ICollider* otherCollider)
	{
		Element::Bunker::BunkerController* bunkerController = dynamic_cast<Element::Bunker::BunkerController*>(otherCollider);
		if (bunkerController) {
			Global::ServiceLocator::getInstance()->getBulletService()->destroyBullet(this);
		}
	}
	void BulletController::moveUp()
	{
		sf::Vector2f currentPosition = getProjectilePosition();
		currentPosition.y -= bulletModel->getMovementSpeed() * Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
		bulletModel->setBulletPosition(currentPosition);
	}
	void BulletController::moveDown()
	{
		sf::Vector2f currentPosition = getProjectilePosition();
		currentPosition.y += bulletModel->getMovementSpeed() * Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
		bulletModel->setBulletPosition(currentPosition);
	}
	void BulletController::handleOutOfBounds()
	{
		sf::Vector2f bulletPosition = getProjectilePosition();
		sf::Vector2u windowSize = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->getSize();

		if (bulletPosition.x < 0 || bulletPosition.x > windowSize.x ||
			bulletPosition.y < 0 || bulletPosition.y > windowSize.y)
		{
			Global::ServiceLocator::getInstance()->getBulletService()->destroyBullet(this);
		}
	}
	BulletController::BulletController(BulletType type, Entity::EntityType ownerEntityType)
	{
		bulletModel = new BulletModel(type,ownerEntityType);
		bulletView = new BulletView();
	}
	
	BulletController::~BulletController()
	{
		delete(bulletModel);
		delete(bulletView);
	}
	void BulletController::initialize(sf::Vector2f position, Bullet::MovementDirection direction)
	{
		bulletModel->initialize(position, direction);
		bulletView->initialize(this);
	}
	void BulletController::update()
	{
		
		updateProjectilePosition();
		bulletView->update();
		handleOutOfBounds();
	}
	void BulletController::render()
	{
		bulletView->render();
	}
	sf::Vector2f BulletController::getProjectilePosition()
	{
		return bulletModel->getBulletPosition();
	}
	BulletType BulletController::getBulletType()
	{
		return bulletModel->getBulletType();
	}
	Entity::EntityType BulletController::getOwnerEntityType()
	{
		return bulletModel->getOwnerEntityType();
	}
	const sf::Sprite& BulletController::getColliderSprite()
	{
		return bulletView->getBulletSprite();
	}
	void BulletController::onCollision(ICollider* otherCollider)
	{
		processBulletCollision(otherCollider);
		processBunkerCollision(otherCollider);
		processEnemyCollision(otherCollider);
		processPlayerCollision(otherCollider);
	}
}