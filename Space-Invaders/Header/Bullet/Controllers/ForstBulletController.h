#pragma once
#include <SFML/Graphics.hpp>
#include "../BulletController.h"
namespace Bullet {
	namespace Controllers {
		class ForstBulletController : public BulletController{
		private:
			float movementSpeed = 700.f;

		public:
			ForstBulletController(BulletType,Entity::EntityType);
			~ForstBulletController();

			void initialize(sf::Vector2f position, MovementDirection direction) override;

		};
	}
}