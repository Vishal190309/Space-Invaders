#pragma once
#include "SFML/Graphics.hpp"
#include "../../Header/UI/UIElement/ImageView.h"

namespace Player {
class PlayerController;


	class PlayerView {

	private:
		const int playerSpriteWidth = 60;
		const int playerSpriteHeight = 60;

		UIElement::ImageView* playerImage;
		PlayerController* playerController;

		void createUIElements();
		void initializeImage();
		void destroy();
	public:
		PlayerView();
		~PlayerView();

		void initialize(PlayerController* controller);
		void update();
		void render();



	};
}