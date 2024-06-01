#include "../../Header/Player/PlayerView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Player/PlayerController.h"
#include "../../Header/Global/Config.h"

namespace Player {
	void PlayerView::createUIElements()
	{
		playerImage = new UIElement::ImageView();
	}
	void PlayerView::initializeImage()
	{
		playerImage->initialize(Global::Config::playerTexturePath, playerSpriteWidth, playerSpriteHeight, playerController->getPlayerPosition());
	}
	void PlayerView::destroy()
	{
	}
	PlayerView::PlayerView()
	{
		createUIElements();
		
	}

	PlayerView::~PlayerView()
	{
		destroy();
	}

	void PlayerView::initialize(PlayerController* controller)
	{
		playerController = controller;
		initializeImage();
	}

	void PlayerView::update()
	{
		playerImage->setPosition(playerController->getPlayerPosition());
		playerImage->update();
	}

	void PlayerView::render()
	{
		playerImage->render();
	}
}
