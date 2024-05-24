#include "../../../Header/Element/Bunker/BunkerView.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Element/Bunker/BunkerController.h"
namespace Element {
	namespace Bunker {
		void BunkerView::initializeImage()
		{
			if (bunkerTexture.loadFromFile(bunkerTexturePath)) {
				bunkerSprite.setTexture(bunkerTexture);
				scaleSprite();
			}
		}
		void BunkerView::scaleSprite()
		{
			bunkerSprite.setScale(
				width / bunkerSprite.getTexture()->getSize().x,
				height / bunkerSprite.getTexture()->getSize().y
			);
		}
		BunkerView::BunkerView()
		{

		}
		BunkerView::~BunkerView()
		{
		}
		void BunkerView::initialize(BunkerController* controller)
		{
			bunkerController = controller;
			gameWindow = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
			initializeImage();
		}
		void BunkerView::update()
		{
			bunkerSprite.setPosition(bunkerController->getPosition());
		}
		void BunkerView::render()
		{
			gameWindow->draw(bunkerSprite);
		}
	}
}