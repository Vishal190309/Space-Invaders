#pragma once
#include <SFML/Graphics.hpp>

namespace Gameplay {
	
	class GameplayView {
	private:
		const sf::String bgTexturePath = "assets/textures/space_invaders_bg.png";
		
		sf::Texture bgTexture;
		sf::Sprite bgSprite;
		
		sf::RenderWindow* gameWindow;
		void initializeBgSprite();
		void scaleBgSprite();
	public:
		GameplayView();
		~GameplayView();

		void initialize();
		void update();
		void render();

	};
}