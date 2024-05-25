#pragma once
#include <SFML/Graphics.hpp>
namespace UI {
	namespace MainMenu {
		class MainMenuUIController {
		private:

			const float buttonWidth = 400;
			const float buttonHeight = 150;

			sf::Texture backgroundTexture;
			sf::Texture playButtonTexture;
			sf::Texture instructionButtonTexture;
			sf::Texture quitButtonTexture;

			sf::Sprite backgroundSprite;
			sf::Sprite playButtonSprite;
			sf::Sprite instructionButtonSprite;
			sf::Sprite quitButtonSprite;

			sf::RenderWindow* gameWindow;

			void initializeBakcroundImage();
			void scaleBackgroundImage();
			

			void initializeButtons();
			bool loadButtonTexturesFromFile();
			void setButtonSprites();

			void scaleAllButttons();
			void scaleButton(sf::Sprite* buttonToScale);
			void positionButtons();

			void processButtonInteractions();
			bool clickedButton(sf::Sprite*, sf::Vector2f);

		public:
			MainMenuUIController();
			~MainMenuUIController();
			void initialize();
			void update();
			void render();
		};
	}
}