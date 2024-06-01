#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/UI/UIElement/ImageView.h"

namespace Bullet {
	using namespace UI;
	class BulletController;
	enum class BulletType;
	class BulletView {
	private:
		const float bulletSpriteWidth = 18.f;
		const float bulletSpriteHeight = 18.f;

		UIElement::ImageView* bulletImage;
		BulletController* bulletController;

		void createUIElements();
		void initializeImage();
		sf::String getBulletTexturePath();
		void destroy();
	public:
		BulletView();
		~BulletView();

		void initialize(BulletController* controller);
		void update();
		void render();

		sf::Sprite getBulletSprite();

	};
}