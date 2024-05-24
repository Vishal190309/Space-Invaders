#include "../../Header/Event/EventService.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Graphic/GraphicService.h"

namespace Event {
    void EventService::updateMouseButtonsState(ButtonState& currentButtonState, sf::Mouse::Button mouseButton)
    {
        if(sf::Mouse::isButtonPressed(mouseButton)){

            switch (currentButtonState)
            {
            case ButtonState::RELEASED:
                currentButtonState = ButtonState::PRESSED;
                break;
            case ButtonState::PRESSED:
                currentButtonState = ButtonState::HELD;
                break;
            }

        }
        else {
            currentButtonState = ButtonState::RELEASED;
        }
    }
    void EventService::updateKeyboardButtonsState(ButtonState& currentButtonState, sf::Keyboard::Key keyboardButton)
    {
        if (sf::Keyboard::isKeyPressed(keyboardButton)) {

            switch (currentButtonState)
            {
            case ButtonState::RELEASED:
                currentButtonState = ButtonState::PRESSED;
                break;
            case ButtonState::PRESSED:
                currentButtonState = ButtonState::HELD;
                break;
            }

        }
        else {
            currentButtonState = ButtonState::RELEASED;
        }
    }
    EventService::EventService() { game_window = nullptr; }

    EventService::~EventService() = default; //calls the default destructor

    void EventService::initialize()
    {
        game_window = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
    }

    void EventService::update()
    {
        updateMouseButtonsState(LeftMouseButtonState,sf::Mouse::Left);
        updateMouseButtonsState(RightMouseButtonState, sf::Mouse::Right);
        updateKeyboardButtonsState(LeftButtonState, sf::Keyboard::Left);
        updateKeyboardButtonsState(RightButtonState, sf::Keyboard::Right);
        updateKeyboardButtonsState(AButtonState, sf::Keyboard::A);
        updateKeyboardButtonsState(DButtonState, sf::Keyboard::D);
    }

    void EventService::processEvents()
    {
        if (isGameWindowOpen()) {
            while (game_window->pollEvent(game_event)) {
                // Check for window closure
                if (gameWindowWasClosed() || hasQuitGame())
                {
                    game_window->close();
                }
            }
        }
    }

    bool EventService::hasQuitGame() { return (isKeyboardEvent() && pressedEscapeKey()); } // only true if the ESC key is pressed and a keyboard event has been registered

    //checks for if a keyboard key has been pressed
    bool EventService::isKeyboardEvent() { return game_event.type == sf::Event::KeyPressed; }

    bool EventService::pressedLeftKey()
    {
        return LeftButtonState == ButtonState::HELD;
    }

    bool EventService::pressedRightKey()
    {
        return RightButtonState == ButtonState::HELD;
    }

    bool EventService::pressedLeftMouseButton()
    {
        return LeftMouseButtonState == ButtonState::PRESSED;
    }

    bool EventService::pressedRightMouseButton()
    {
        return RightMouseButtonState == ButtonState::PRESSED;
    }

    bool EventService::pressedAKey()
    {
        return AButtonState == ButtonState::HELD;
    }

    bool EventService::pressedDKey()
    {
        return  DButtonState == ButtonState::HELD;
    }

   

    //control click on the SFML functions to see what they do internally
    bool EventService::pressedEscapeKey() { return game_event.key.code == sf::Keyboard::Escape; }

    bool EventService::isGameWindowOpen() { return game_window != nullptr; }

    bool EventService::gameWindowWasClosed() { return game_event.type == sf::Event::Closed; }
}