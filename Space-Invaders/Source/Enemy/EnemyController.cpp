#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Enemy/EnemyModel.h"

namespace Enemy {
	EnemyController::EnemyController()
	{
		enemyModel = new EnemyModel();
		enemyView = new EnemyView();
		
		
	}
	EnemyController::~EnemyController()
	{
		delete(enemyModel);
		delete(enemyView);
	}
	void EnemyController::initialize()
	{
		enemyModel->initialize();
		enemyView->initialize(this);
	}
	void EnemyController::update()
	{
		enemyView->update();
	}
	void EnemyController::render()
	{
		enemyView->render();
	}
	sf::Vector2f EnemyController::getEnemyPosition()
	{
		return enemyModel->getEnemyPosition();
	}
}