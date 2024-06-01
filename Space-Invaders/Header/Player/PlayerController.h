#pragma once

#include <SFML/Graphics.hpp>
#include "../../Header/Entity/EntityConfig.h"

namespace Player {
	class PlayerView;
	class PlayerModel;
	class PlayerController {

	private:
		PlayerView* playerView;
		PlayerModel* playerModel;

		void processPlayerInput();
		void moveLeft();
		void moveRight();
		void fireBullet();

	public:
		PlayerController(Entity::EntityType entityType);
		~PlayerController();

		void initialize();
		void update();
		void render();

		sf::Vector2f getPlayerPosition();
		Entity::EntityType getEntityType();

	};
}
