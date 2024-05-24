#pragma once
#include <SFML/Graphics.hpp>
namespace Enemy {
	class EnemyModel;
	class EnemyView;
	class EnemyController {
		
	private:
		EnemyView* enemyView;
		EnemyModel* enemyModel;

		virtual void move()=0;
		void moveLeft();
		void moveRight();
		void moveDown();
	public:
		EnemyController();
		virtual ~EnemyController();

		virtual void initialize();
		void update();
		void render();
		sf::Vector2f getEnemyPosition();

		
	};
}