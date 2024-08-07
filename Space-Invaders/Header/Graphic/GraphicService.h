#pragma once
#include <SFML/Graphics.hpp>
namespace Graphic {
	class GraphicService {

	private:
		


		int game_window_width = 1920;
		int game_window_height = 1080;

		sf::Color windowColor = sf::Color::Blue;

		sf::VideoMode* videoMode;
		sf::RenderWindow* gameWindow;

		void setVideoMode();
		void onDestroy();
		const int frameRate = 60;

	public:

		GraphicService();
		~GraphicService();
		sf::RenderWindow* createGameWindow();

		void initialize();
		void update();
		void render();
		bool isGameWindowOpen();

		sf::RenderWindow* getGameWindow(); //getter for the game window instance
		sf::Color getWindowColor();


	};
}