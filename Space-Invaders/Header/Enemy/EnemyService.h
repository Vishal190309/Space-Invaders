#pragma once
#include <vector>
#include "../../Header/Entity/EntityConfig.h"


namespace Enemy {
	class EnemyController;
	enum class EnemyType;
	class EnemyService {
	private:
		std::vector<EnemyController*> enemyList;
		const float spawnDelay = 1.5f;
		float spawnTimer;
		void udpateSpawnTimer();
		void processEnemySpawn();
		void destroy();
		EnemyType getRandomEnemyType();
		EnemyController* createEnemy(EnemyType type, Entity::EntityType entityType);
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
