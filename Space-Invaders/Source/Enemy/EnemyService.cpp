#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Enemy/EnemyController.h"

namespace Enemy {
	EnemyService::EnemyService()
	{
		enemyController = nullptr;
	}
	EnemyService::~EnemyService()
	{
		destroy();
	}
	void EnemyService::initialize()
	{
		spawnEnemy();
	}
	void EnemyService::update()
	{
		enemyController->update();
	}
	void EnemyService::render()
	{
		enemyController->render();
	}
	void EnemyService::destroy()
	{
		delete(enemyController);
	}
	EnemyController* EnemyService::spawnEnemy()
	{
		enemyController = new EnemyController();
		enemyController->initialize();
		return enemyController;
	}
}