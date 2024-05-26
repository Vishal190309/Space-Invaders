#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Projectile/IProjectile.h"
namespace Bullet {
	class BulletController;
	enum class BulletType;
	enum class MovementDirection;
	class BulletService {
	private:
		std::vector<Projectile::IProjectile*> listOfProjectile;
		BulletController* createBullet(BulletType type);
		void destroy();

	public:
		BulletService();
		~BulletService();

		void initialize();
		void update();
		void render();

		void spawnBullet(BulletType type,sf::Vector2f position, MovementDirection direction);
		void destroyBullet(BulletController* controller);

	};
}