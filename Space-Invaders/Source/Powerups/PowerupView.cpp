#include "../../Header/Powerups/PowerupView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Powerups/PowerupController.h"
#include "../../Header/Powerups/PowerupConfig.h"

namespace Powerup {
	using namespace Global;
	void PowerupView::initializeImage(PowerupType type)
	{
		switch (type)
		{
		case::Powerup::PowerupType::TRIPPLE_LASER:
			if (powerupTexture.loadFromFile(Config::trippleLaserTexturePath))
			{
				powerupSprite.setTexture(powerupTexture);
				scaleImage();
			}
			break;
		case::Powerup::PowerupType::SHIELD:
			if (powerupTexture.loadFromFile(Config::shieldTexturePath))
			{
				powerupSprite.setTexture(powerupTexture);
				scaleImage();
			}
			break;
		case::Powerup::PowerupType::RAPID_FIRE:
			if (powerupTexture.loadFromFile(Config::rapidFireTexturePath))
			{
				powerupSprite.setTexture(powerupTexture);
				scaleImage();
			}
			break;
		case::Powerup::PowerupType::OUTSCAL_BOMB:
			if (powerupTexture.loadFromFile(Config::outscalBombTexturePath))
			{
				powerupSprite.setTexture(powerupTexture);
				scaleImage();
			}
			break;
		}
	}
	void PowerupView::scaleImage()
	{
		powerupSprite.setScale(
			static_cast<float>(powerupWidth) / powerupSprite.getTexture()->getSize().x,
			static_cast<float>(powerupHeight) / powerupSprite.getTexture()->getSize().y
		);
	}
	void PowerupView::destroy()
	{
	}
	PowerupView::PowerupView()
	{
	}
	PowerupView::~PowerupView()
	{
		destroy();
	}
	void PowerupView::initialize(PowerupController* controller)
	{
		powerupController = controller;
		gameWindow = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		initializeImage(powerupController->getPowerupType());
	}
	void PowerupView::update()
	{
		powerupSprite.setPosition(powerupController->getCollectiblePosition());
	}
	void PowerupView::render()
	{
		gameWindow->draw(powerupSprite);
	}
}