#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Enemy/EnemyConfig.h"
namespace Enemy {
	using namespace Global;

	void EnemyView::createUIElemetns()
	{
		enemyImage = new UIElement::ImageView();
	}
	void EnemyView::initializeImage()
	{
		enemyImage->initialize(getEnemyTexturePath(),enemyWidth,enemyHeight,enemyController->getEnemyPosition());

	}
	sf::String EnemyView::getEnemyTexturePath()
	{
		switch (enemyController->getEnemyType()) {
		case EnemyType::SUBZERO:
			return Config::subzeroTexturePath;
			break;
		case EnemyType::ZAPPER:
			return Config::zapperTexturePath;
			break;
		case EnemyType::THUNDER_SNAKE:
			return Config::thunderSnakeTexturePath;
			break;

		case EnemyType::UFO:
			return Config::ufoTexturePath;
			break;
		default:
			return Config::subzeroTexturePath;
			break;
		}
	}
	void EnemyView::destroy()
	{
		delete(enemyImage);
	}
	EnemyView::EnemyView()
	{
		createUIElemetns();
		
	}
	EnemyView::~EnemyView()
	{
		destroy();
	}
	void EnemyView::initialize(EnemyController* enemyController)
	{
		this->enemyController = enemyController;
		initializeImage();

	}
	void EnemyView::update()
	{
		enemyImage->setPosition(enemyController->getEnemyPosition());
		enemyImage->update();
	}
	void EnemyView::render()
	{
		enemyImage->render();
	}
}