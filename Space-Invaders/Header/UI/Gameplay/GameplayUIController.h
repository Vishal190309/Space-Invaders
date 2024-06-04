#pragma once
#include "../../header/UI/Interface/IUIController.h"
#include "../../header/UI/UIElement/ImageView.h"
#include "../../header/UI/UIElement/ButtonView.h"
#include "../../header/UI/UIElement/TextView.h"


namespace UI {
	namespace GameplayUI {
		class GameplayUIController : public Interface::IUIController {
		private:
			const sf::Color textColor = sf::Color::White;
			const float fontSize = 40.f;
			const sf::Vector2f textPosition = sf::Vector2f(60.f,15.f);


			const float playerSpriteWidth= 30.f;
			const float playerSpriteHeight= 30.f;
			const sf::Vector2f playerLivesPosition = sf::Vector2f(1850.f, 25.f);
			const float playerLivesSpacing = 60.f;

			UI::UIElement::ImageView* playerImage;
			UI::UIElement::TextView* enemiesKilledText;


			void createUIElements();
			void initializeText();
			void initializeImage();
			void destroy();
		public:

			GameplayUIController();
			virtual ~GameplayUIController();

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;

			void updateEnemiesKilledText();
			void drawPlayerLives();


		};
	}
}