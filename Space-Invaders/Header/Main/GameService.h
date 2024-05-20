#pragma once
#include "../../Header/Global/ServiceLocator.h"
#include "SFML/Graphics.hpp"

namespace Main {
	enum class GameState {
		BOOT,
		MAIN_MENU,
		GAMEPLAY
	};
	class GameService {
	private:
		Global::ServiceLocator* serviceLocator;
		sf::RenderWindow* gameWindow;
		void initialize();
		void initializeVariable();
		void destroy();
		static GameState currentState;

		void showMainMenu();

	public:
		GameService();

		~GameService();
		void ignite();
		void update();
		void render();
		bool isRunning();

		static void setGameState(GameState newState);

		static GameState getGameState();

	};
}