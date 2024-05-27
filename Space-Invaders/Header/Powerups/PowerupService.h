#pragma once
#include <vector>
#include "SFML/System/Vector2.hpp"
#include "../../Header/Collectible/ICollectible.h"


namespace Powerup {
	class PowerupController;
	enum class PowerupType;
	class PowerupService {
	private:
		PowerupType powerupType;
		std::vector<Collectible::ICollectible> listOfPowerups;

		PowerupController* createPowerup(PowerupType powerupType);
		void destroy();

	public:
		PowerupService();
		~PowerupService();

		void initialize();
		void update();
		void render();

		PowerupController* spawnPowerup(PowerupType powerType, sf::Vector2f position);
		void destroyPowerup(PowerupController* powerupController);
	};
}