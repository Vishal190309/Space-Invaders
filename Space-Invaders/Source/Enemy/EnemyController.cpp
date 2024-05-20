#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Enemy {
	using namespace Global;
	void EnemyController::move()
	{
		switch (enemyModel->getEnemyMovementDirection())
		{
		case MovementDirection::Left:
			moveLeft();
			break;
		case MovementDirection::Right:
			moveRight();
			break;
		case MovementDirection::Down:
			moveDown();
			break;

		}
	}
	void EnemyController::moveLeft()
	{
		sf::Vector2f currentPosition = enemyModel->getEnemyPosition();
		currentPosition.x -= (enemyModel->enemyMovementSpeed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime());
		if (currentPosition.x < enemyModel->leftMostPosition.x) {
			enemyModel->setReferencePosition(currentPosition);
			enemyModel->setEnemyMovementDirection(MovementDirection::Down);
		}
		else {
			enemyModel->setEnemyPosition(currentPosition);
		}
	}
	void EnemyController::moveRight()
	{
		sf::Vector2f currentPosition = enemyModel->getEnemyPosition();
		currentPosition.x += (enemyModel->enemyMovementSpeed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime());
		if (currentPosition.x > enemyModel->RightMostPosition.x) {
			enemyModel->setReferencePosition(currentPosition);
			enemyModel->setEnemyMovementDirection(MovementDirection::Down);
		}
		else {
			enemyModel->setEnemyPosition(currentPosition);
		}
	}
	void EnemyController::moveDown()
	{
		sf::Vector2f currentPosition = enemyModel->getEnemyPosition();
		currentPosition.y += (enemyModel->enemyMovementSpeed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime());
		if (currentPosition.y > enemyModel->getReferencePosition().y + enemyModel->DownMoveDistance) {
			if(enemyModel->getReferencePosition().x <= enemyModel->leftMostPosition.x){
				enemyModel->setEnemyMovementDirection(MovementDirection::Right);
			}
			else if (enemyModel->getReferencePosition().x >= enemyModel->RightMostPosition.x) {
				enemyModel->setEnemyMovementDirection(MovementDirection::Left);
			}
			
		}
		else {
			enemyModel->setEnemyPosition(currentPosition);
		}
	}
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
		move();
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