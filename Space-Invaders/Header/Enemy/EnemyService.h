#pragma once
#include <vector>

namespace Enemy {
	class EnemyController;
	class EnemyService {
	private:
		std::vector<EnemyController*> enemyList;
		const float spawnDelay = 3.f;
		float spawnTimer;
		void udpateSpawnTimer();
		void processEnemySpawn();
		void destroy();
	public:
		EnemyService();
		virtual ~EnemyService();

		void initialize();
		void update();
		void render();
		
		void spawnEnemy();
	};
}
