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

	public:
		GameService();

		~GameService();
		void ignite();
		void update();
		void render();
		bool isRunning();

		void setGameState(GameState newState);

		GameState getGameState();

	};
}