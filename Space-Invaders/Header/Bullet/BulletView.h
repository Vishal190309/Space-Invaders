#pragma once
#include <SFML/Graphics.hpp>
namespace Bullet {
	class BulletController;
	enum class BulletType;
	class BulletView {
	private:
		const float bulletSpriteWidth = 18.f;
		const float bulletSpriteHeight = 18.f;

		sf::Texture bulletTexture;
		sf::Sprite bulletSprite;

		sf::RenderWindow* gameWindow;
		BulletController* bulletController;

		void initializeImage(BulletType type);
		void scaleImage();
	public:
		BulletView();
		~BulletView();

		void initialize(BulletController* controller);
		void update();
		void render();

	};
}