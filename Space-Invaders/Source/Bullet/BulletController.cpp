#include "../../Header/Bullet/BulletController.h"
#include "../../Header/Bullet/BulletModel.h"
#include "../../Header/Bullet/BulletView.h"
#include "../../Header/Bullet/BulletConfig.h"
#include "../../Header/Global/ServiceLocator.h"
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
	BulletController::BulletController(BulletType type)
	{
		bulletModel = new BulletModel(type);
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
}