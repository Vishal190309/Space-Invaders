#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy {
	enum class MovementDirection {
		Left,
		Right,
		Down
	};
	class EnemyModel {
	private:
		sf::Vector2f enemyPosition;
		sf::Vector2f referencePosition= sf::Vector2f(50.f, 50.f);;
		MovementDirection enemyMovementDirection;
		
	public:
		EnemyModel();
		~EnemyModel();

		void initialize();
		void reset();


		const sf::Vector2f leftMostPosition = sf::Vector2f(50.f, 950.f);
		const sf::Vector2f RightMostPosition = sf::Vector2f(1800.f, 950.f);

		const float  DownMoveDistance = 100.f;
		const float enemyMovementSpeed = 250.f;


		sf::Vector2f getEnemyPosition();
		void setEnemyPosition(sf::Vector2f position);

		sf::Vector2f getReferencePosition();
		void setReferencePosition(sf::Vector2f position);

		MovementDirection getEnemyMovementDirection();
		void setEnemyMovementDirection(MovementDirection newMovementDirection);

	};
}