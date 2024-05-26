#pragma once
#include <SFML/Graphics.hpp>
#include "../../Global/Config.h"
namespace Element {
	namespace Bunker {
		class BunkerController;
		class BunkerView {
		private:
			const float width = 80.f;
			const float height = 80.f;
			
			sf::Texture bunkerTexture;
			sf::Sprite bunkerSprite;

			BunkerController* bunkerController;
			sf::RenderWindow* gameWindow;

			void initializeImage();
			void scaleSprite();
		public:
			BunkerView();
			~BunkerView();

			void initialize(BunkerController* controller);
			void update();
			void render();
		};


	}
}