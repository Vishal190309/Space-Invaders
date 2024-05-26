#include "../../../Header/Bullet/Controllers/TorpedoeController.h"
#include "../../../Header/Bullet/BulletModel.h"
namespace Bullet {
	namespace Controllers {
		TorpedoeBulletController::TorpedoeBulletController(BulletType type) : BulletController(type)
		{

		}

		TorpedoeBulletController::~TorpedoeBulletController()
		{
		}

		void TorpedoeBulletController::initialize(sf::Vector2f position, MovementDirection direction)
		{
			BulletController::initialize(position, direction);
			bulletModel->setMovementSpeed(movementSpeed);
		}

	}
}

