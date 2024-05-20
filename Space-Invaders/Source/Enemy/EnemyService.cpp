#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Time/TimeService.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Enemy {
	using namespace Global;
	using namespace Time;
	EnemyService::EnemyService()
	{
		enemyList.clear();
	}
	EnemyService::~EnemyService()
	{
		destroy();
	}
	void EnemyService::initialize()
	{
		spawnTimer = spawnDelay;
	}
	void EnemyService::update()
	{
		udpateSpawnTimer();
		processEnemySpawn();
		for (int i = 0; i < enemyList.size();i++) {
			enemyList[i]->update();
		}
	}
	void EnemyService::render()
	{
		for (int i = 0; i < enemyList.size(); i++) {
			enemyList[i]->render();
		}
	}
	void EnemyService::udpateSpawnTimer()
	{
		spawnTimer += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
		
	}
	void EnemyService::processEnemySpawn()
	{
		if (spawnTimer > spawnDelay) {
			spawnEnemy();
			spawnTimer = 0.f;
		}
	}
	void EnemyService::destroy()
	{
		for (int i = 0; i < enemyList.size(); i++) {
			delete(enemyList[i]);
		}

		enemyList.clear();
	}
	void EnemyService::spawnEnemy()
	{
		EnemyController* enemyController = new EnemyController();
		enemyController->initialize();
		enemyList.push_back(enemyController);
	}
}