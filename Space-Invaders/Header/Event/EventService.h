#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
namespace Event {
	enum class ButtonState
	{
		PRESSED,
		HELD,
		RELEASED,
	};
	class EventService
	{
	private:
		sf::Event game_event; //event var
		sf::RenderWindow* game_window; //ptr to our game window

		bool isGameWindowOpen();
		bool gameWindowWasClosed(); //for the condition we already had - the title bar cross.
		bool hasQuitGame(); //for our new 'ESC' condition
		ButtonState AButtonState = ButtonState::RELEASED ;
		ButtonState DButtonState = ButtonState::RELEASED;
		ButtonState LeftButtonState = ButtonState::RELEASED;
		ButtonState RightButtonState = ButtonState::RELEASED;
		ButtonState LeftMouseButtonState = ButtonState::RELEASED;
		ButtonState RightMouseButtonState = ButtonState::RELEASED;

		void updateMouseButtonsState(ButtonState& currentButtonState, sf::Mouse::Button mouseButton);
		void updateKeyboardButtonsState(ButtonState& currentButtonState, sf::Keyboard::Key keyboardButton);



	public:
		EventService();
		~EventService();

		void initialize();
		void update();
		void processEvents(); // while window is open we will check for events
		bool pressedEscapeKey();
		bool isKeyboardEvent();
		bool pressedLeftKey();
		bool pressedRightKey();
		bool pressedLeftMouseButton();
		bool pressedRightMouseButton();
		bool pressedAKey();
		bool pressedDKey();


	};
}