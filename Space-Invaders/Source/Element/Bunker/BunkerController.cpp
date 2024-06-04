#include "../../../Header/Element/Bunker/BunkerController.h"
#include "../../../Header/Element/Bunker/BunkerView.h"
#include "../../Header/Bullet/BulletController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../../header/Bullet/BulletConfig.h"

namespace Element {
	namespace Bunker {
		BunkerController::BunkerController()
		{
			bunkerView = new BunkerView();
		}
		BunkerController::~BunkerController()
		{
			delete(bunkerView);
		}
		void BunkerController::initialize(BunkerData data)
		{
			bunkerData = data;
			bunkerView->initialize(this);
		}
		void BunkerController::update()
		{
			bunkerView->update();
		}
		void BunkerController::render()
		{
			bunkerView->render();
		}
		sf::Vector2f BunkerController::getPosition()
		{
			return bunkerData.position;
		}

		const sf::Sprite& BunkerController::getColliderSprite()
		{
			return bunkerView->getBunkerSprite();
		}

		void BunkerController::onCollision(ICollider* otherCollider)
		{
			Bullet::BulletController* bullet_controller = dynamic_cast<Bullet::BulletController*>(otherCollider);

			if (bullet_controller && bullet_controller->getBulletType() == Bullet::BulletType::TORPEDO)
			{
				Global::ServiceLocator::getInstance()->getElementService()->destroyBunker(this);
			}
		}
		
	}
}