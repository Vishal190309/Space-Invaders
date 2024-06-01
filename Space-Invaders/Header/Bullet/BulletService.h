#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Projectile/IProjectile.h"
#include "../../Header/Entity/EntityConfig.h"

namespace Bullet {
	class BulletController;
	enum class BulletType;
	enum class MovementDirection;
	class BulletService {
	private:
		std::vector<Projectile::IProjectile*> listOfFlaggedBullets;
		std::vector<Projectile::IProjectile*> listOfProjectile;
		BulletController* createBullet(BulletType type,Entity::EntityType ownerEntityType);

		bool isValidBullet(int indexI, std::vector<Projectile::IProjectile*>& bulletList);
		void destroyFlaggedBullets();

		void destroy();

	public:
		BulletService();
		~BulletService();

		void initialize();
		void update();
		void render();

		void spawnBullet(BulletType type,sf::Vector2f position, MovementDirection direction, Entity::EntityType ownerEntityType);
		void destroyBullet(BulletController* controller);

	};
}