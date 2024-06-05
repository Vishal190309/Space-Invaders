#include "../../Header/UI/SplashScreenUI/SplashScreenUIController.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Main/GameService.h"

namespace UI {
	namespace SplashScreenUI {
		void SplashScreenUIController::initializeOutscalLogo()
		{
			outscaleLogoView->initialize(Global::Config::outscalLogoTexturePath, logoWidth, logoHeight, getLogoPosition());
		}
		void SplashScreenUIController::updateTimer()
		{
			elapsedDuration += Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
			
		}
		void SplashScreenUIController::showMainMenu()
		{
			if (elapsedDuration >= splashScreenDuration)
			{
				Global::ServiceLocator::getInstance()->getSoundService()->playBackgroundMusic();
				Main::GameService::setGameState(Main::GameState::MAIN_MENU);
			}

		}
		sf::Vector2f SplashScreenUIController::getLogoPosition()
		{
			sf::RenderWindow* game_window = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

			float xPosition = (game_window->getSize().x - logoWidth) / 2.0f;
			float yPosition = (game_window->getSize().y - logoHeight) / 2.0f;

			return sf::Vector2f(xPosition, yPosition);
		}
		SplashScreenUIController::SplashScreenUIController()
		{
			outscaleLogoView = new UIElement::ImageView();
		}
		SplashScreenUIController::~SplashScreenUIController()
		{
			delete(outscaleLogoView);
		}
		void SplashScreenUIController::initialize()
		{
			initializeOutscalLogo();
		}
		void SplashScreenUIController::update()
		{
			updateTimer();
			showMainMenu();
		}
		void SplashScreenUIController::render()
		{
			outscaleLogoView->render();
		}
		void SplashScreenUIController::show()
		{
			
		}
	}
}