#pragma once
#include <SFML/System/Vector2.hpp>
namespace Powerup {
	enum class PowerupType;
	class PowerupModel {
	private:
		sf::Vector2f powerupPosition;
		PowerupType powerupType;
		float movementSpeed = 200.f;
	public:
		PowerupModel(PowerupType type);
		~PowerupModel();

		void initialize(sf::Vector2f position);

		sf::Vector2f getPowerupPosition();
		void setPowerupPosition(sf::Vector2f position);

		PowerupType getPowerupType();
		void setPowerupType(PowerupType type);

		float getMovementSpeed();
		void setMovementSpeed(float movementSpeed);
		




	};
}