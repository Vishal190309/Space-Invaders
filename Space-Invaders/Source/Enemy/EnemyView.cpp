#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Global/ServiceLocator.h"
namespace Enemy {
	using namespace Global;
	void EnemyView::initializeSprite()
	{
		if (enemyTexture.loadFromFile(enemyTexturePath)){
			enemySprite.setTexture(enemyTexture);
			scaleSprite();
		}
	}
	void EnemyView::scaleSprite()
	{
		enemySprite.setScale(
			enemyWidth / enemySprite.getTexture()->getSize().x,
			enemyHeight / enemySprite.getTexture()->getSize().y
		);
	}
	EnemyView::EnemyView()
	{
		enemyController = nullptr;
		gameWindow = nullptr;
	}
	EnemyView::~EnemyView()
	{
	}
	void EnemyView::initialize(EnemyController* enemyController)
	{
		this->enemyController = enemyController;
		gameWindow = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		initializeSprite();

	}
	void EnemyView::update()
	{
		enemySprite.setPosition(enemyController->getEnemyPosition());
	}
	void EnemyView::render()
	{
		gameWindow->draw(enemySprite);
	}
}