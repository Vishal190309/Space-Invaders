#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Entity/EntityConfig.h"

namespace Bullet {
	enum class BulletType;
	enum class MovementDirection;

	class BulletModel {
	private:
		float bulletMovementSpeed = 300.f;
		sf::Vector2f bulletPosition;
		BulletType bulletType;
		MovementDirection movementDirection;
		Entity::EntityType ownerEntityType;

	public:
		BulletModel(BulletType type,Entity::EntityType ownerEntityType);
		~BulletModel();

		void initialize(sf::Vector2f, MovementDirection direction);

		sf::Vector2f getBulletPosition();
		void setBulletPosition(sf::Vector2f position);

		BulletType getBulletType();
		void setBulletType(BulletType type);

		MovementDirection getMovementDirection();
		void setMovementDirection(MovementDirection direction);

		float getMovementSpeed();
		void setMovementSpeed(float speed);
		Entity::EntityType getOwnerEntityType();
	};
}