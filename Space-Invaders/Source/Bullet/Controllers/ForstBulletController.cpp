#include "../../../Header/Bullet/Controllers/ForstBulletController.h"
#include "../../../Header/Bullet/BulletModel.h"

namespace Bullet {
	namespace Controllers {
		ForstBulletController::ForstBulletController(BulletType type):BulletController(type)
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