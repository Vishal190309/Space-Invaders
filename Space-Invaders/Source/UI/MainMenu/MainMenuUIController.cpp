#include "../../Header/UI/MainMenu/MainMenuUIController.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Graphic/GraphicService.h"
#include "../../../Header/UI/UIElement/ButtonView.h"
#include "../../../Header/UI/UIElement/ImageView.h"

namespace UI
{
    namespace MainMenu //nested namespace since everything in MainMenu exists inside UI
    {
        using namespace Global;
        using namespace Main;
        using namespace Graphic;
        using namespace Event;
        using namespace Sound;
        using namespace UIElement;

        MainMenuUIController::MainMenuUIController() { 
            createImage();
            createButton();
        }

        MainMenuUIController::~MainMenuUIController()
        {
            destroy();
        }

        void MainMenuUIController::initialize()
        {
            initializeBackgroundImage();
            initializeButtons();
            registerButtonCallback();
        }

        void MainMenuUIController::update()
        {
            backgroundImage->update();
            playButton->update();
            instructionsButton->update();
            quitButton->update();

        }

        void MainMenuUIController::render()

        {
            backgroundImage->render();
            playButton->render();
            instructionsButton->render();
            quitButton->render();
        }

        void MainMenuUIController::show()
        {
            backgroundImage->show();
            playButton->show();
            instructionsButton->show();
            quitButton->show();

            ServiceLocator::getInstance()->getSoundService()->playBackroundMusic();
        }

      


        void MainMenuUIController::createImage()
        {
            backgroundImage = new ImageView();
        }

        void MainMenuUIController::createButton()
        {
            playButton = new ButtonView();
            instructionsButton = new ButtonView();
            quitButton = new ButtonView();
        }

        void MainMenuUIController::initializeBackgroundImage()
        {
            sf::RenderWindow* gameWindow = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
            backgroundImage->initialize(Config::backgroundTexturePath, gameWindow->getSize().x, gameWindow->getSize().y, sf::Vector2f(0.f, 0.f));
            backgroundImage->setImageAlpha(backgroundAlpha);
        }

        void MainMenuUIController::initializeButtons()
        {
            playButton->initialize("Play Button", Config::playButtonTexturePath, buttonWidth, buttonHeight, sf::Vector2f(0, playButtonYPosition));
            instructionsButton->initialize("Instructions Button", Config::instructionsButtonTexturePath, buttonWidth, buttonHeight, sf::Vector2f(0, instructionsButtonYPosition));
            quitButton->initialize("Quit Button", Config::quitButtonTexturePath, buttonWidth, buttonHeight, sf::Vector2f(0, quitButtonYPosition));

            playButton->setCentreAlinged();
            instructionsButton->setCentreAlinged();
            quitButton->setCentreAlinged();

        }

        void MainMenuUIController::registerButtonCallback()
        {
            playButton->registerCallbackFuntion(std::bind(&MainMenuUIController::playButtonCallback, this));
            instructionsButton->registerCallbackFuntion(std::bind(&MainMenuUIController::intstructionButtonCallback, this));
            quitButton->registerCallbackFuntion(std::bind(&MainMenuUIController::quitButtonCallback, this));
        }

        void MainMenuUIController::playButtonCallback()
        {
            ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
            GameService::setGameState(GameState::GAMEPLAY);
        }

        void MainMenuUIController::intstructionButtonCallback()
        {
            ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
        }

        void MainMenuUIController::quitButtonCallback()
        {
            ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
            ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->close();
        }

        void MainMenuUIController::destroy()
        {
         
            delete(playButton);
            delete(quitButton);
            delete(instructionsButton);
            delete(backgroundImage);
        }

       

    }
}