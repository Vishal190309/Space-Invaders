#pragma once

#include <SFML/Graphics.hpp>
#include "../../Header/Entity/EntityConfig.h"
#include "../../Header/Collision/ICollider.h"

namespace Player {
	class PlayerView;
	class PlayerModel;
	class PlayerController : public Collision::ICollider {

	private:
		float elapsedShieldDuration;
		float elapsedRapidFireDuration;
		float elapsedTripperLaserDuration;

		float elapsedFireDuration;
		float elapsedFreezeDuration;

		PlayerView* playerView;
		PlayerModel* playerModel;

		void processPlayerInput();
		void moveLeft();
		void moveRight();


		bool processBulletCollision(ICollider* otherCollider);
		bool processPowerupCollision(ICollider* otherCollider);
		bool processEnemyCollision(ICollider* otherCollider);
		void updateFreezDuration();
		void freezPlayer();

		void updateFireDuration();
		void processBulletFire();
		void fireBullet(bool bTrippleLaser = false);
		void fireBullet(sf::Vector2f position);

		void updatePowerupDuration();

		void disableShield();
		void disableRapidFire();
		void disableTrippleLaser();

	public:
		PlayerController(Entity::EntityType entityType);
		~PlayerController();

		void initialize();
		void update();
		void render();

		void reset();

		void enableShield();
		void enableRapidFire();
		void enableTrippleLaser();

		sf::Vector2f getPlayerPosition();
		Entity::EntityType getEntityType();


		const sf::Sprite& getColliderSprite();
		void onCollision(ICollider* otherCollider);

	};
}
