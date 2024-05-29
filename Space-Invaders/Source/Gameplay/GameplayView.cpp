#include "../../Header/Gameplay/GameplayView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"

namespace Gameplay {
	using namespace Global;
	
	
	void GameplayView::createUIElements()
	{
		backgroundImage = new UIElement::ImageView();
	}
	void GameplayView::initializeImage()
	{
		backgroundImage->setOriginAtCentre();
		backgroundImage->initialize(Config::backgroundTexturePath, gameWindow->getSize().x, gameWindow->getSize().y, sf::Vector2f(gameWindow->getSize().x/2, gameWindow->getSize().y/2));
		
	}
	void GameplayView::destroy()
	{
		delete(backgroundImage);
	}
	GameplayView::GameplayView()
	{
		
		createUIElements();
		gameWindow = nullptr;

	}
	GameplayView::~GameplayView()
	{
		destroy();
	}
	void GameplayView::initialize()
	{
		gameWindow = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		initializeImage();
		
	}
	void GameplayView::update()
	{
	}
	void GameplayView::render()
	{
		backgroundImage->render();
	}
}