#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/UI/UIElement/ImageView.h"

namespace Gameplay {
	using namespace UI;
	class GameplayView {
	private:
		sf::RenderWindow* gameWindow;
		UIElement::ImageView* backgroundImage;
		void createUIElements();
		void initializeImage();
		void destroy();
	public:
		GameplayView();
		~GameplayView();

		void initialize();
		void update();
		void render();

	};
}