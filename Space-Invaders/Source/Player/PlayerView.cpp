#include "../../Header/Player/PlayerView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Player/PlayerController.h"
#include "../../Header/Global/Config.h"

namespace Player {
	void PlayerView::initializePlayerSprite()
	{
		if (playerTexture.loadFromFile(Global::Config::playerTexturePath)) {
			playerSprite.setTexture(playerTexture);
			scalePlayerSprite();
		}
	}



	void PlayerView::scalePlayerSprite()
	{
		playerSprite.setScale(
			static_cast<float>(playerSpriteWidth) / playerSprite.getTexture()->getSize().x,
			static_cast<float>(playerSpriteHeight) / playerSprite.getTexture()->getSize().y
		);
	}

	PlayerView::PlayerView()
	{

	}

	PlayerView::~PlayerView()
	{
	}

	void PlayerView::initialize(PlayerController* controller)
	{
		playerController = controller;
		gameWindow = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		initializePlayerSprite();
	}

	void PlayerView::update()
	{
		playerSprite.setPosition(playerController->getPlayerPosition());
	}

	void PlayerView::render()
	{
		gameWindow->draw(playerSprite);
	}
}
