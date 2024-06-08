#include "../../../Header/UI/UIElement/ImageView.h"

namespace UI {
	namespace UIElement {
		ImageView::ImageView() = default;
		ImageView::~ImageView() = default;
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
		void ImageView::setTextureRect(sf::IntRect textureRect)
		{
			sprite.setTextureRect(textureRect);
		}
		
		void ImageView::setScale(float xScale, float yScale)
		{
			float scaleX = xScale / sprite.getTexture()->getSize().x;
			float scaleY = yScale / sprite.getTexture()->getSize().y;
			sprite.setScale(scaleX , scaleY);
		}
		void ImageView::setScale(float width, float height, float tileWidth, float tileHeight)
		{
			float scaleX = width / tileWidth;
			float scaleY = height / tileHeight;
			sprite.setScale(scaleX, scaleY);
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
			float positionX = (gameWindow->getSize().x / 2) -(sprite.getGlobalBounds().width / 2);
			float positionY = sprite.getGlobalBounds().getPosition().y;

			sprite.setPosition(positionX, positionY);
		}
		
		const sf::Sprite& ImageView::getSprite()
		{
			return sprite;
		}
	}
}