#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Time/TimeService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Enemy/Controllers/SubZeroController.h"
#include "../../Header/Enemy/Controllers/ZapperController.h"
#include "../../Header/Enemy/Controllers/ThunderSnakeController.h"
#include "../../Header/Enemy/Controllers/UFOController.h"
#include <iostream>

namespace Enemy {
	using namespace Global;
	using namespace Time;
	EnemyService::EnemyService()
	{
		std::srand(static_cast<unsigned>(std::time(nullptr)));
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
		enemyController = createEnemy(getRandomEnemyType(),Entity::EntityType::ENEMY);
		enemyController->initialize();
		enemyList.push_back(enemyController);
	}

	EnemyType EnemyService::getRandomEnemyType()
	{
		int randomEnemyType = std::rand() % 4;
		return static_cast<Enemy::EnemyType>(randomEnemyType);
	}
	EnemyController* EnemyService::createEnemy(EnemyType type, Entity::EntityType entityType)
	{
		switch (type) {
		case EnemyType::SUBZERO:
			return new Controllers::SubZeroController(type, entityType);
			break;
		case EnemyType::ZAPPER:
			return new Controllers::ZapperController(type, entityType);
			break;
		case EnemyType::THUNDER_SNAKE:
			return new Controllers::ThunderSnakeController(type, entityType);
			break;
		case EnemyType::UFO:
			return new Controllers::UFOController(type, entityType);
			break;
		default:
			return new Controllers::SubZeroController(type, entityType);
			break;
			
		}
		
	}
	void EnemyService::destroyEnemy(EnemyController* controller)
	{
		enemyList.erase(std::remove(enemyList.begin(), enemyList.end(), controller), enemyList.end());
		delete(controller);
	
	}
}