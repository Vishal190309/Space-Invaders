#pragma once
#include <SFML/Graphics.hpp>
#include "..\UI\UIElement\ImageView.h"
namespace Powerup {
	using namespace UI;
	class PowerupController;
	enum class PowerupType;

	class PowerupView {
	private:
		const float powerupWidth = 30.f;
		const float powerupHeight = 30.f;

		UIElement::ImageView* powerupImage;
		PowerupController* powerupController;

		void createUIElements();
		void initializeImage();
		sf::String getPowerupTexturPath();
		void destroy();

	public:
		PowerupView();
		~PowerupView();

		void initialize(PowerupController* controller);
		void update();
		void render();


	};
}