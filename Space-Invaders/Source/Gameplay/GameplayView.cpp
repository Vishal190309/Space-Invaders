#include "../../Header/Gameplay/GameplayView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"

namespace Gameplay {
	using namespace Global;
	void GameplayView::initializeBgSprite()
	{
		if (bgTexture.loadFromFile(Config::backgroundTexturePath)) {
			bgSprite.setTexture(bgTexture);
			scaleBgSprite();
		}
	}
	void GameplayView::scaleBgSprite()
	{
		bgSprite.setScale(
			static_cast<float>(gameWindow->getSize().x) / bgSprite.getTexture()->getSize().x,
			static_cast<float>(gameWindow->getSize().y) / bgSprite.getTexture()->getSize().y
		);
	}
	GameplayView::GameplayView()
	{
		gameWindow = nullptr;
	}
	GameplayView::~GameplayView()
	{
	}
	void GameplayView::initialize()
	{
		gameWindow = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		initializeBgSprite();
		
	}
	void GameplayView::update()
	{
	}
	void GameplayView::render()
	{
		gameWindow->draw(bgSprite);
	}
}