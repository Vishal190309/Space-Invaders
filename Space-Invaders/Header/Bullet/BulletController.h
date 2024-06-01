#pragma once
#include "../Projectile/IProjectile.h"
#include "../../Header/Entity/EntityConfig.h"
#include "../../Header/Collision/ICollider.h"

namespace Bullet {
	enum class BulletType;
	class BulletModel;
	class BulletView;

	class BulletController : public Projectile::IProjectile ,public Collision::ICollider{
	protected:

		BulletModel* bulletModel;
		BulletView* bulletView;

		void updateProjectilePosition() override;

		void processBulletCollision(ICollider* otherCollider);
		void processEnemyCollision(ICollider* otherCollider);
		void processPlayerCollision(ICollider* otherCollider);
		void processBunkerCollision(ICollider* otherCollider);

		void moveUp();
		void moveDown();
		void handleOutOfBounds();
	public:
		BulletController(BulletType type, Entity::EntityType ownerEntityType);
		virtual ~BulletController();

		void initialize(sf::Vector2f position, Bullet::MovementDirection direction) override;
		void update() override;
		void render() override;
		sf::Vector2f getProjectilePosition() override;
		BulletType getBulletType();
		Entity::EntityType getOwnerEntityType();

		const sf::Sprite& getColliderSprite() override;
		void onCollision(ICollider* otherCollider) override;
	};
}