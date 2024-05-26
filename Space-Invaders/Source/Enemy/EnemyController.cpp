#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Enemy {
	using namespace Global;
	/*void EnemyController::move()
	{
		switch (enemyModel->getEnemyMovementDirection())
		{
		case MovementDirection::LEFT:
			moveLeft();
			break;
		case MovementDirection::RIGHT:
			moveRight();
			break;
		case MovementDirection::DOWN:
			moveDown();
			break;

		}
	}*/
	/*void EnemyController::moveLeft()
	{
		sf::Vector2f currentPosition = enemyModel->getEnemyPosition();
		currentPosition.x -= (enemyModel->enemyMovementSpeed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime());
		if (currentPosition.x < enemyModel->leftMostPosition.x) {
			enemyModel->setReferencePosition(currentPosition);
			enemyModel->setEnemyMovementDirection(MovementDirection::DOWN);
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
			enemyModel->setEnemyMovementDirection(MovementDirection::DOWN);
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
				enemyModel->setEnemyMovementDirection(MovementDirection::RIGHT);
			}
			else if (enemyModel->getReferencePosition().x >= enemyModel->RightMostPosition.x) {
				enemyModel->setEnemyMovementDirection(MovementDirection::LEFT);
			}
			
		}
		else {
			enemyModel->setEnemyPosition(currentPosition);
		}
	}*/
	void EnemyController::updateFireTimer()
	{
		elapsedFireDuration += Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
	}
	void EnemyController::processBulletFire()
	{
		if (elapsedFireDuration >= rateOfFire) {
			fireBullet();
			elapsedFireDuration = 0.f;
		}
	}
	sf::Vector2f EnemyController::getRandomInitialPosition()
	{
		float xOffsetDistance = (std::rand() % static_cast<int>(enemyModel->rightMostPosition.x - enemyModel->leftMostPosition.x));
		float xPosition = enemyModel->leftMostPosition.x + xOffsetDistance;
		float yPosition = enemyModel->leftMostPosition.y;
		return sf::Vector2f(xPosition, yPosition);
	}
	void EnemyController::handleOutOfBounds()
	{
		sf::Vector2f enemyPosition = getEnemyPosition();
		sf::Vector2u windowSize = ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->getSize();

		// Destroy the enemy if it goes out of bounds.
		if (enemyPosition.x < 0 || enemyPosition.x > windowSize.x ||
			enemyPosition.y < 0 || enemyPosition.y > windowSize.y)
		{
			ServiceLocator::getInstance()->getEnemyService()->destroyEnemy(this);
		}
	}
	EnemyController::EnemyController(EnemyType type)
	{
		enemyModel = new EnemyModel(type);
		enemyView = new EnemyView();
		
		
	}
	EnemyController::~EnemyController()
	{
		delete(enemyModel);
		delete(enemyView);
	}
	void EnemyController::initialize()
	{
		enemyModel->setReferencePosition(getRandomInitialPosition());
		enemyModel->initialize();
		enemyView->initialize(this);
		
	}
	void EnemyController::update()
	{
		move();
		updateFireTimer();
		processBulletFire();
		enemyView->update();
		handleOutOfBounds();

	}
	void EnemyController::render()
	{
		if(enemyView){
		enemyView->render();
		}
	}
	sf::Vector2f EnemyController::getEnemyPosition()
	{
		return enemyModel->getEnemyPosition();
	}
	EnemyState EnemyController::getEnemyState()
	{
		return EnemyState();
	}
	EnemyType EnemyController::getEnemyType()
	{
		return enemyModel->getEnemyType();
	}
}