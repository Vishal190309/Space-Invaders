#include "../../../Header/Bullet/Controllers/LaserBulletController.h"

namespace Bullet {
	namespace Controllers {
		LaserBulletController::LaserBulletController(BulletType type , Entity::EntityType ownerEntityType) : BulletController(type, ownerEntityType)
		{
		
		}

		LaserBulletController::~LaserBulletController()
		{
		}
		void LaserBulletController::initialize(sf::Vector2f position, MovementDirection direction)
		{
			BulletController::initialize(position, direction);
		}
	}
}


