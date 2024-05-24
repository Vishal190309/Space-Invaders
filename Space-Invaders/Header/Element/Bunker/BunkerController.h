#pragma once
#include <SFML/Graphics.hpp>
#include "BunkerModel.h"
namespace Element {
	namespace Bunker {
		class BunkerView;
		class BunkerController {
		private:
			BunkerView* bunkerView;
			BunkerData* bunkerData;

		public:
			BunkerController();
			~BunkerController();

			void initialize(BunkerData data);
			void update();
			void render();


			sf::Vector2f getPosition();

		};
	}
}