#include "../../Header/Bullet/BulletView.h"
#include "../../Header/Bullet/BulletController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Bullet/BulletConfig.h"

namespace Bullet {
	using namespace Global;

	void BulletView::createUIElements()
	{
		bulletImage = new UIElement::ImageView();
	}
	void BulletView::initializeImage()
	{
		bulletImage->initialize(getBulletTexturePath(), bulletSpriteWidth, bulletSpriteHeight, bulletController->getProjectilePosition());
	}
	sf::String BulletView::getBulletTexturePath()
	{
		switch (bulletController->getBulletType()) {
		case BulletType::LASER_BULLET:
			return Config::laserBulletTexturePath;
			break;
		case BulletType::FROST_BULLET:
			return Config::frostBeamTexturePath;
			break;
		case BulletType::TORPEDO:
			return Config::torpedoeTexturePath;
			break;
		}
	}
	void BulletView::destroy()
	{
		delete(bulletImage);
	}
	BulletView::BulletView()
	{
		createUIElements();
	}
	BulletView::~BulletView()
	{
		destroy();
	}
	void BulletView::initialize(BulletController* controller)
	{
		bulletController = controller;
		initializeImage();

	}
	void BulletView::update()
	{
		bulletImage->setPosition(bulletController->getProjectilePosition());
		bulletImage->update();
	}
	void BulletView::render()
	{
		bulletImage->render();
	}
}