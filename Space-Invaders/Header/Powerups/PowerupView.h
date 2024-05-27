#pragma once
#include <SFML/Graphics.hpp>
namespace Powerup {
	class PowerupController;
	enum class PowerupType;

	class PowerupView {
	private:
		const float powerupWidth = 30.f;
		const float powerupHeight = 30.f;
		sf::Texture powerupTexture;
		sf::Sprite powerupSprite;

		sf::RenderWindow* gameWindow;
		PowerupController* powerupController;

		void initializeImage(PowerupType type);
		void scaleImage();
		void destroy();
	public:
		PowerupView();
		~PowerupView();

		void initialize(PowerupController* controller);
		void update();
		void render();


	};
}