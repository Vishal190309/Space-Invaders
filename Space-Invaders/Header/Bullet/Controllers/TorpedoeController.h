#pragma once
#include <SFML/Graphics.hpp>
#include "../BulletController.h"
namespace Bullet {
	namespace Controllers {
		class TorpedoeBulletController:public BulletController {
		private:
			float movementSpeed = 300.f;

		public:
			TorpedoeBulletController(BulletType, Entity::EntityType);
			~TorpedoeBulletController();

			void initialize(sf::Vector2f position, MovementDirection direction) override;

		};
	}
}