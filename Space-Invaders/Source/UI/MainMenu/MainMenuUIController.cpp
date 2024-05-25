#include "../../Header/UI/MainMenu/MainMenuUIController.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Graphic/GraphicService.h"

namespace UI
{
    namespace MainMenu //nested namespace since everything in MainMenu exists inside UI
    {
        using namespace Global;
        using namespace Main;
        using namespace Graphic;
        using namespace Event;
        using namespace Sound;

        MainMenuUIController::MainMenuUIController() { gameWindow = nullptr; }

        MainMenuUIController::~MainMenuUIController()
        {
        }

        void MainMenuUIController::initialize()
        {
            gameWindow = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
            initializeBakcroundImage();
            initializeButtons();
        }

        void MainMenuUIController::update()
        {
            processButtonInteractions();
        }

        void MainMenuUIController::render()
        {
            gameWindow->draw(backgroundSprite);
            gameWindow->draw(playButtonSprite);
            gameWindow->draw(instructionButtonSprite);
            gameWindow->draw(quitButtonSprite);
        }

        void MainMenuUIController::initializeBakcroundImage()
        {
            if (backgroundTexture.loadFromFile(Config::backgroundTexturePath)) {
                backgroundSprite.setTexture(backgroundTexture);
                scaleBackgroundImage();
            }
           
        }

        void MainMenuUIController::scaleBackgroundImage()
        {
            backgroundSprite.setScale(
                static_cast<float>(gameWindow->getSize().x) / backgroundSprite.getTexture()->getSize().x,
                static_cast<float>(gameWindow->getSize().y) / backgroundSprite.getTexture()->getSize().y
            );
        }

        void MainMenuUIController::initializeButtons()
        {
            if (loadButtonTexturesFromFile()) {
                setButtonSprites();
                scaleAllButttons();
                positionButtons();
                
            }
        }

        bool MainMenuUIController::loadButtonTexturesFromFile()
        {
            
             return playButtonTexture.loadFromFile(Config::playButtonTexturePath)
                 && instructionButtonTexture.loadFromFile(Config::instructionsButtonTexturePath)
                   && quitButtonTexture.loadFromFile(Config::quitButtonTexturePath);
            
        }

        void MainMenuUIController::setButtonSprites()
        {
            playButtonSprite.setTexture(playButtonTexture);
            instructionButtonSprite.setTexture(instructionButtonTexture);
            quitButtonSprite.setTexture(quitButtonTexture);
        }

        void MainMenuUIController::scaleAllButttons()
        {
            scaleButton(&playButtonSprite);
            scaleButton(&instructionButtonSprite);
            scaleButton(&quitButtonSprite);
            
        }

        void MainMenuUIController::scaleButton(sf::Sprite* buttonToScale)
        {
            buttonToScale->setScale(
                buttonWidth / buttonToScale->getTexture()->getSize().x,
                buttonHeight / buttonToScale->getTexture()->getSize().y
            );
        }

        void MainMenuUIController::positionButtons()
        {
            float xPosition = static_cast<float>(gameWindow->getSize().x / 2)-(buttonWidth/2);
            playButtonSprite.setPosition(xPosition, 500.0f);
            instructionButtonSprite.setPosition(xPosition, 700.0f);
            quitButtonSprite.setPosition(xPosition, 900.0f);
        }

        void MainMenuUIController::processButtonInteractions()
        {
           
            sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(*gameWindow));
            if (clickedButton(&playButtonSprite, mousePosition)) {

                ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
                ServiceLocator::getInstance()->getSoundService()->playBackroundMusic();
                GameService::setGameState(GameState::GAMEPLAY);
            }
            if (clickedButton(&instructionButtonSprite, mousePosition)) {
                ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
                ServiceLocator::getInstance()->getSoundService()->playBackroundMusic();
                printf("Clicked instruction button\n");
            }
            if (clickedButton(&quitButtonSprite, mousePosition)) {
                ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
                ServiceLocator::getInstance()->getSoundService()->playBackroundMusic();
                gameWindow->close();
            }
        }

        bool MainMenuUIController::clickedButton(sf::Sprite* buttonSprite, sf::Vector2f mousePosition)
        {
            EventService* eventService = ServiceLocator::getInstance()->getEventService();
          
            return eventService->pressedLeftMouseButton() && buttonSprite->getGlobalBounds().contains(gameWindow->mapPixelToCoords(static_cast<sf::Vector2i> (mousePosition)));
        }

    }
}