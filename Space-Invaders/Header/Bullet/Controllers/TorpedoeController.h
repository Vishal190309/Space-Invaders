#pragma once
#include <SFML/Graphics.hpp>
#include "../BulletController.h"
namespace Bullet {
	namespace Controllers {
		class TorpedoeBulletController:public BulletController {
		private:
			float movementSpeed = 200.f;

		public:
			TorpedoeBulletController(BulletType);
			~TorpedoeBulletController();

			void initialize(sf::Vector2f position, MovementDirection direction) override;

		};
	}
}