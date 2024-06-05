#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/UI/Interface/IUIController.h"
#include "../../Header/UI/UIElement/ImageView.h"
namespace UI {
	namespace SplashScreenUI {

		class SplashScreenUIController : public Interface::IUIController{
		private:
			const float splashScreenDuration = 2.0f;
			float elapsedDuration = 0.0f;
			const float logoWidth = 600.f;
			const float logoHeight = 134.f;
			const sf::Vector2f imagePosition;

			UIElement::ImageView* outscaleLogoView;

			void initializeOutscalLogo();
			void updateTimer();
			void showMainMenu();
			sf::Vector2f getLogoPosition();
		public:
			SplashScreenUIController();
			~SplashScreenUIController();
			void initialize() override;
			void update() override;
			void render() override;
			void show() override;

		};

	}
}