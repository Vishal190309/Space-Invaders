#pragma once
#include <SFML/Graphics.hpp>
#include "../BulletController.h"
namespace Bullet {
	namespace Controllers {
		class LaserBulletController : public BulletController {
		public:
			LaserBulletController(BulletType,Entity::EntityType);
			~LaserBulletController();

			void initialize(sf::Vector2f position, MovementDirection direction) override;

		};
	}
}