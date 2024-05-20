#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy {
	class EnemyModel {
	private:
		sf::Vector2f enemyPosition;
		sf::Vector2f referencePosition= sf::Vector2f(50.f, 50.f);;
	public:
		EnemyModel();
		~EnemyModel();

		void initialize();
		void reset();

		sf::Vector2f getEnemyPosition();
		void setEnemyPosition(sf::Vector2f position);

		sf::Vector2f getReferencePosition();
		void setReferencePosition(sf::Vector2f position);
	};
}