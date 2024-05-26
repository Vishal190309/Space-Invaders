#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy {
	class EnemyModel;
	class EnemyView;
	enum class EnemyType;
	enum class EnemyState;
	class EnemyController {
		
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

	public:
		EnemyController(EnemyType type);
		virtual ~EnemyController();

		virtual void initialize();
		void update();
		void render();
		sf::Vector2f getEnemyPosition();
		EnemyState getEnemyState();
		EnemyType getEnemyType();

		
	};
}