#pragma once
#include <SFML/Graphics.hpp>
#include "../Interface/IUIController.h"
#include "../UIElement/ButtonView.h"
#include "../UIElement/ImageView.h"
namespace UI {
	namespace MainMenu {
		class MainMenuUIController : public Interface::IUIController {
		private:

			const float buttonWidth = 400;
			const float buttonHeight = 150;
			
			const float playButtonYPosition = 400.f;
			const float instructionsButtonYPosition = 600.f;
			const float quitButtonYPosition = 800.f;
			const float backgroundAlpha = 85.f;


			UIElement::ImageView* backgroundImage;
			UIElement::ButtonView* playButton;
			UIElement::ButtonView* instructionsButton;
			UIElement::ButtonView* quitButton;


			void createImage();
			void createButton();
			void initializeBackgroundImage();

			void initializeButtons();
			void registerButtonCallback();

			void playButtonCallback();
			void intstructionButtonCallback();
			void quitButtonCallback();

			void destroy();

		public:
			MainMenuUIController();
			~MainMenuUIController();

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;
		};
	}
}