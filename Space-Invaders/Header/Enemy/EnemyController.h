#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Entity/EntityConfig.h"
#include "../../Header/Collision/ICollider.h"


namespace Enemy {
	class EnemyModel;
	class EnemyView;
	enum class EnemyType;
	enum class EnemyState;
	class EnemyController : public Collision::ICollider{
		
	private:
		

		
		
		/*void moveLeft();
		void moveRight();
		void moveDown();*/
	protected:
		
		EnemyView* enemyView;
		EnemyModel* enemyModel;

		float rateOfFire = 3.f;
		float elapsedFireDuration = 0.f;

		void updateFireTimer();
		void processBulletFire();
		virtual void fireBullet() = 0;
		virtual void move() = 0;
		sf::Vector2f getRandomInitialPosition();
		void handleOutOfBounds();
		void destroy();

	public:
		EnemyController(EnemyType type,Entity::EntityType entityType);
		virtual ~EnemyController();

		virtual void initialize();
		void update();
		void render();
		sf::Vector2f getEnemyPosition();
		EnemyState getEnemyState();
		EnemyType getEnemyType();
		Entity::EntityType getEntityType();


		const sf::Sprite& getColliderSprite() override;
		void onCollision(ICollider* otherCollider) override;
	};
}