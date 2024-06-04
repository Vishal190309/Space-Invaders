#include "../../Header/UI/Gameplay/GameplayUIController.h"
#include "../../Header/Global/Config.h";
#include "../../header/Player/PlayerModel.h"
#include "../../Header/Global/ServiceLocator.h"

namespace UI {
	namespace GameplayUI {
		using namespace Global;
		using namespace Player;
		void GameplayUIController::createUIElements()
		{
			playerImage = new UI::UIElement::ImageView();
			enemiesKilledText = new UI::UIElement::TextView();
		}
		void GameplayUIController::initializeText()
		{
			playerImage->initialize(Config::playerTexturePath,playerSpriteWidth,playerSpriteHeight,playerLivesPosition);
			
		}
		void GameplayUIController::initializeImage()
		{
			sf::String enemiesKilledString = "Enemies Killed  :  0";
			enemiesKilledText->initialize(enemiesKilledString,textPosition,UI::UIElement::FontType::BUBBLE_BOBBLE,fontSize,textColor);
		}
		void GameplayUIController::destroy()
		{
			delete(playerImage);
			delete(enemiesKilledText);
		}
		GameplayUIController::GameplayUIController()
		{
			createUIElements();
		}
		GameplayUIController::~GameplayUIController()
		{
			destroy();
		}
		void GameplayUIController::initialize()
		{
			initializeText();
			initializeImage();
		}
		void GameplayUIController::update()
		{
			updateEnemiesKilledText();
		}
		void GameplayUIController::render()
		{
			enemiesKilledText->render();
			drawPlayerLives();
		}
		void GameplayUIController::show()
		{
		}
		void GameplayUIController::updateEnemiesKilledText()
		{
			sf::String enemiesKilledString = "Enemies Killed  :  " + std::to_string(PlayerModel::enemiesKilled);
			enemiesKilledText->setText(enemiesKilledString);
		}
		void GameplayUIController::drawPlayerLives()
		{
			sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

			for (int i = 0; i < PlayerModel::playerLives; i++)
			{
				playerImage->setPosition(sf::Vector2f(playerLivesPosition.x - (i * playerLivesSpacing), playerLivesPosition.y));
				playerImage->render();
			}
		}
	}
}