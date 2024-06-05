#include "../../Header/Bullet/BulletService.h"
#include "../../Header/Bullet/BulletConfig.h"
#include "../../Header/Bullet/BulletController.h"
#include "../../Header/Bullet/Controllers/LaserBulletController.h"
#include "../../Header/Bullet/Controllers/ForstBulletController.h"
#include "../../Header/Bullet/Controllers/TorpedoeController.h"
#include "../../Header/Projectile/IProjectile.h"
#include "../../Header/Global/ServiceLocator.h"


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
	bool BulletService::isValidBullet(int indexI, std::vector<Projectile::IProjectile*>& bulletList)
	{
		return indexI>=0 && indexI < bulletList.size() && bulletList[indexI] != nullptr;
	}
	void BulletService::destroyFlaggedBullets()
	{
		for (int i = 0; i < listOfFlaggedBullets.size(); i++) {
			if (isValidBullet(i, listOfFlaggedBullets)) {
				Global::ServiceLocator::getInstance()->getCollisionService()->removeCollider(dynamic_cast<Collision::ICollider*>(listOfFlaggedBullets[i]));
				delete(listOfFlaggedBullets[i]);
			}
		}
		listOfFlaggedBullets.clear();
	}
	void BulletService::destroy()
	{
		for (int i = 0; i < listOfProjectile.size(); i++) {
			delete(listOfProjectile[i]);
		}
	}
	BulletService::BulletService()
	{
		listOfFlaggedBullets.clear();
		listOfProjectile.clear();
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
		destroyFlaggedBullets();
	}
	void BulletService::render()
	{
		for (int i = 0; i < listOfProjectile.size(); i++) {
			listOfProjectile[i]->render();
		}
	}
	BulletController* BulletService::spawnBullet(BulletType type, sf::Vector2f position, MovementDirection direction, Entity::EntityType ownerEntityType)
	{
		BulletController* controller = createBullet(type,ownerEntityType);
		controller->initialize(position, direction);
		Global::ServiceLocator::getInstance()->getCollisionService()->addCollider(dynamic_cast<Collision::ICollider*>(controller));
		listOfProjectile.push_back(controller);
		return controller;
	}
	void BulletService::destroyBullet(BulletController* controller)
	{
		
		if (std::find(listOfFlaggedBullets.begin(), listOfFlaggedBullets.end(), controller) == listOfFlaggedBullets.end())
		{
			listOfFlaggedBullets.push_back(controller);
			listOfProjectile.erase(std::remove(listOfProjectile.begin(), listOfProjectile.end(), controller), listOfProjectile.end());
		}
	}
	void BulletService::reset()
	{
		destroy();
	}
}
