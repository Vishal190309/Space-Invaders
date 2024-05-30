#include "../../../Header/UI/UIElement/ImageView.h"

namespace UI {
	namespace UIElement {

		void ImageView::initialize(sf::String texturePath, float imageWidth, float imageHeight, sf::Vector2f postion)
		{
			UIView::initialize();
			setTexture(texturePath);
			setScale(imageWidth, imageHeight);
			setPosition(postion);
		}
		void ImageView::update()
		{
			UIView::update();
		}
		void ImageView::render()
		{
			UIView::render();
			if (uiState == UIState::VISIBLE) {
				gameWindow->draw(sprite);
			}
		}
		void ImageView::setTexture(sf::String texturePath)
		{
			if (texture.loadFromFile(texturePath)) {
				sprite.setTexture(texture);
			}
		}
		void ImageView::setScale(float xScale, float yScale)
		{
			sprite.setScale(
				xScale / sprite.getTexture()->getSize().x,
				yScale / sprite.getTexture()->getSize().y
			);
		}
		void ImageView::setPosition(sf::Vector2f position)
		{
			sprite.setPosition(position);
		}
		void ImageView::setRotation(float angle)
		{
			sprite.setRotation(angle);
		}
		void ImageView::setOriginAtCentre()
		{
			sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
		}
		void ImageView::setImageAlpha(float alpha)
		{
			sf::Color color = sprite.getColor();
			color.a = alpha;
			sprite.setColor(color);
		}
		void ImageView::setCentreAlinged()
		{
			float positionX = (gameWindow->getSize().x / 2 - sprite.getGlobalBounds().width / 2);
			float positionY = sprite.getGlobalBounds().getSize().y;

			sprite.setPosition(positionX, positionY);
		}
	}
}