#pragma once
#include <vector>

namespace Enemy {
	class EnemyController;
	enum class EnemyType;
	class EnemyService {
	private:
		std::vector<EnemyController*> enemyList;
		const float spawnDelay = 3f;
		float spawnTimer;
		void udpateSpawnTimer();
		void processEnemySpawn();
		void destroy();
		EnemyType getRandomEnemyType();
		EnemyController* createEnemy(EnemyType type);
		EnemyController* enemyController;
	public:
		EnemyService();
		virtual ~EnemyService();

		void initialize();
		void update();
		void render();
		
		void spawnEnemy();
		void destroyEnemy(EnemyController* controller);
	};
}
