#include "../../Header/Bullet/BulletView.h"
#include "../../Header/Bullet/BulletController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Bullet/BulletConfig.h"

namespace Bullet {
	using namespace Global;
	void BulletView::initializeImage(BulletType type)
	{
		switch (type) {
		case BulletType::LASER_BULLET:
			if (bulletTexture.loadFromFile(Config::laserBulletTexturePath))
			{
				bulletSprite.setTexture(bulletTexture);
				scaleImage();
			}
			break;
		case BulletType::FROST_BULLET:
			if (bulletTexture.loadFromFile(Config::frostBeamTexturePath))
			{
				bulletSprite.setTexture(bulletTexture);
				scaleImage();
			}
			break;
		case BulletType::TORPEDO:
			if (bulletTexture.loadFromFile(Config::torpedoeTexturePath))
			{
				bulletSprite.setTexture(bulletTexture);
				scaleImage();
			}
			break;
		}
		
	}
	void BulletView::scaleImage()
	{
		bulletSprite.setScale(
			bulletSpriteWidth / bulletSprite.getTexture()->getSize().x,
			bulletSpriteHeight / bulletSprite.getTexture()->getSize().y
			);
	}
	BulletView::BulletView()
	{

	}
	BulletView::~BulletView()
	{
	}
	void BulletView::initialize(BulletController* controller)
	{
		bulletController = controller;
		gameWindow = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		initializeImage(bulletController->getBulletType());

	}
	void BulletView::update()
	{
		bulletSprite.setPosition(bulletController->getProjectilePosition());
	}
	void BulletView::render()
	{
		gameWindow->draw(bulletSprite);
	}
}