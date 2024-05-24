#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Enemy/EnemyConfig.h"
namespace Enemy {
	class EnemyModel;
	class EnemyView;
	class EnemyController {
		
	private:
		

		virtual void move()=0;
		void moveLeft();
		void moveRight();
		void moveDown();
	protected:
		EnemyView* enemyView;
		EnemyModel* enemyModel;
	public:
		EnemyController(EnemyType type);
		virtual ~EnemyController();

		virtual void initialize();
		void update();
		void render();
		sf::Vector2f getEnemyPosition();
		EnemyType getEnemyType();

		
	};
}