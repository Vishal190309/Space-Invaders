#include "../../Header/Powerups/PowerupView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Powerups/PowerupController.h"
#include "../../Header/Powerups/PowerupConfig.h"

namespace Powerup {
	using namespace Global;
	

	void PowerupView::createUIElements()
	{
		powerupImage = new UIElement::ImageView();
	}
	void PowerupView::initializeImage()
	{
		powerupImage->initialize(getPowerupTexturPath(), powerupWidth, powerupHeight, powerupController->getPowerupPosition());

	}
	sf::String PowerupView::getPowerupTexturPath()
	{
		switch (powerupController->getPowerupType())
		{
		case::Powerup::PowerupType::TRIPPLE_LASER:
			return Config::trippleLaserTexturePath;
			break;
		case::Powerup::PowerupType::SHIELD:
			return Config::shieldTexturePath;
			break;
		case::Powerup::PowerupType::RAPID_FIRE:
			return Config::rapidFireTexturePath;
			break;
		case::Powerup::PowerupType::OUTSCAL_BOMB:
			return Config::outscalBombTexturePath;
			break;
		default:
			return Config::trippleLaserTexturePath;
			break;
		}
	}
	void PowerupView::destroy()
	{
		delete(powerupImage);
	}
	PowerupView::PowerupView()
	{
		createUIElements();
	}
	PowerupView::~PowerupView()
	{
		destroy();
	}
	void PowerupView::initialize(PowerupController* controller)
	{
		powerupController = controller;
		initializeImage();
	}
	void PowerupView::update()
	{
		powerupImage->setPosition(powerupController->getPowerupPosition());
		powerupImage->update();
	}
	void PowerupView::render()
	{
		powerupImage->render();
	}
}