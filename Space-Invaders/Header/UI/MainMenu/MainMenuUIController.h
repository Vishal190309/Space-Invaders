#pragma once
#include <SFML/Graphics.hpp>
namespace UI {
	namespace MainMenu {
		class MainMenuUIController {
		private:
			const sf::String backgroundTexturePath = "assets/textures/space_invaders_bg.png";
			const sf::String playButtonTexturePath = "assets/textures/play_button.png";
			const sf::String instructionButtonTexturePath = "assets/textures/instructions_button.png";
			const sf::String quitButtonTexturePath = "assets/textures/quit_button.png";

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

		public:
			MainMenuUIController();
			~MainMenuUIController();
			void initialize();
			void update();
			void render();
		};
	}
}