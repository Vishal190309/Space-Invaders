#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Global/ServiceLocator.h"
namespace Enemy {
	using namespace Global;
	void EnemyView::initializeSprite(EnemyType type)
	{
		switch (type) {
		case EnemyType::SUBZERO:
			if (enemyTexture.loadFromFile(subzeroTexturePath)) {
				enemySprite.setTexture(enemyTexture);
				scaleSprite();
			}
			break;
		case EnemyType::ZAPPER:
			if (enemyTexture.loadFromFile(zapperTexturePath)) {
				enemySprite.setTexture(enemyTexture);
				scaleSprite();
			}
			break;
		case EnemyType::THUNDER_SNAKE:
			break;
		case EnemyType::UFO :
			break;
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
		initializeSprite(this->enemyController->getEnemyType());

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