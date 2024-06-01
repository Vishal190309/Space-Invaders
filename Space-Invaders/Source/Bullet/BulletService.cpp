#include "../../Header/Bullet/BulletService.h"
#include "../../Header/Bullet/BulletConfig.h"
#include "../../Header/Bullet/BulletController.h"
#include "../../Header/Bullet/Controllers/LaserBulletController.h"
#include "../../Header/Bullet/Controllers/ForstBulletController.h"
#include "../../Header/Bullet/Controllers/TorpedoeController.h"
#include "../../Header/Projectile/IProjectile.h"


namespace Bullet {
	BulletController* BulletService::createBullet(BulletType type, Entity::EntityType ownerEntityType)
	{
		switch (type)
		{
		case Bullet::BulletType::LASER_BULLET:
			return new Controllers::LaserBulletController(type,ownerEntityType);
			break;
		case Bullet::BulletType::TORPEDO:
			new Controllers::TorpedoeBulletController(type, ownerEntityType);
			break;
		case Bullet::BulletType::FROST_BULLET:
			new Controllers::ForstBulletController(type, ownerEntityType);
			break;
		}
	}
	void BulletService::destroy()
	{
		for (int i = 0; i < listOfProjectile.size(); i++) {
			delete(listOfProjectile[i]);
		}
	}
	BulletService::BulletService()
	{
	}
	BulletService::~BulletService()
	{
		destroy();
	}
	void BulletService::initialize()
	{
	}
	void BulletService::update()
	{
		for (int i = 0; i < listOfProjectile.size(); i++) {
			listOfProjectile[i]->update();
		}
	}
	void BulletService::render()
	{
		for (int i = 0; i < listOfProjectile.size(); i++) {
			listOfProjectile[i]->render();
		}
	}
	void BulletService::spawnBullet(BulletType type, sf::Vector2f position, MovementDirection direction, Entity::EntityType ownerEntityType)
	{
		BulletController* controller = createBullet(type,ownerEntityType);
		controller->initialize(position, direction);
		listOfProjectile.push_back(controller);
	}
	void BulletService::destroyBullet(BulletController* controller)
	{
		
		listOfProjectile.erase(std::remove(listOfProjectile.begin(), listOfProjectile.end(), controller), listOfProjectile.end());
		delete(controller);
	}
}
