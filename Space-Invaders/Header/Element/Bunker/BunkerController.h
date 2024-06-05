#pragma once
#include <SFML/Graphics.hpp>
#include "BunkerModel.h"
#include "../../Header/Collision/ICollider.h"
namespace Element {
	namespace Bunker {
		class BunkerView;
		class BunkerController : public Collision::ICollider{
		private:
			BunkerView* bunkerView;
			BunkerData bunkerData;

		public:
			BunkerController();
			~BunkerController();

			void initialize(BunkerData data);
			void update();
			void render();


			sf::Vector2f getPosition();

			const sf::Sprite& getColliderSprite();
			void onCollision(ICollider* otherCollider);
		};
	}
}