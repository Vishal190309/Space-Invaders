#pragma once


namespace Enemy {
	class EnemyController;
	class EnemyService {
	private:
		EnemyController* enemyController;
		void destroy();
	public:
		EnemyService();
		virtual ~EnemyService();

		void initialize();
		void update();
		void render();
		
		EnemyController* spawnEnemy();
	};
}
