#pragma once
#include <SFML/Graphics.hpp>
#include "../../Global/Config.h"
#include "../../Header/UI/UIElement/ImageView.h"
namespace Element {
	namespace Bunker {
		class BunkerController;
		class BunkerView {
		private:
			const float width = 80.f;
			const float height = 80.f;

			UIElement::ImageView* bunkerImage;
			BunkerController* bunkerController;

			void createUIElemetns();
			void initializeImage();
			sf::String getBunkerTexturePath();
			void destroy();

		public:
			BunkerView();
			~BunkerView();

			void initialize(BunkerController* controller);
			void update();
			void render();
		};


	}
}