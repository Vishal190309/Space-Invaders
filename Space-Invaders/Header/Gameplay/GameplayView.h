#pragma once
#include <SFML/Graphics.hpp>

namespace Gameplay {
	
	class GameplayView {
	private:
	
		
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