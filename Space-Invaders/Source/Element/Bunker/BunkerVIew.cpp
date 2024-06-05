#include "../../../Header/Element/Bunker/BunkerView.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Element/Bunker/BunkerController.h"
#include "../../../Header/Global/Config.h"
namespace Element {
	using namespace Global;
	namespace Bunker {
		void BunkerView::createUIElemetns()
		{
			bunkerImage = new UIElement::ImageView();
		}
		void BunkerView::initializeImage()
		{
			bunkerImage->initialize(getBunkerTexturePath(), width, height, bunkerController->getPosition());
		}
		sf::String BunkerView::getBunkerTexturePath()
		{
			return Config::bunkerTexturePath;
		}
		void BunkerView::destroy()
		{
			delete(bunkerImage);
		}
		
		BunkerView::BunkerView()
		{
			createUIElemetns();
		}
		BunkerView::~BunkerView()
		{
			destroy();
		}
		void BunkerView::initialize(BunkerController* controller)
		{
			bunkerController = controller;
			initializeImage();
		}
		void BunkerView::update()
		{
			bunkerImage->setPosition(bunkerController->getPosition());
			bunkerImage->update();
		}
		void BunkerView::render()
		{
			bunkerImage->render();
		}
		const sf::Sprite& BunkerView::getBunkerSprite()
		{
			return bunkerImage->getSprite();
		}
	}
}