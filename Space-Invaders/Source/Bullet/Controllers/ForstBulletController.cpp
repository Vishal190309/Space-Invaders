#include "../../../Header/Bullet/Controllers/ForstBulletController.h"
#include "../../../Header/Bullet/BulletModel.h"

namespace Bullet {
	namespace Controllers {
		ForstBulletController::ForstBulletController(BulletType type, Entity::EntityType ownerEntityType):BulletController(type,ownerEntityType)
		{
		}
		ForstBulletController::~ForstBulletController()
		{
		}
		void ForstBulletController::initialize(sf::Vector2f position, MovementDirection direction)
		{
			BulletController::initialize(position, direction);
			bulletModel->setMovementSpeed(movementSpeed);
		}
	}
}