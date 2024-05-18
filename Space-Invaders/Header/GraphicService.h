#pragma once
#include <SFML/Graphics.hpp>
class GraphicService {

private:
	const std::string game_window_title = "Test";


	int game_window_width=800;
	int game_window_height=600;

	sf::Color windowColor = sf::Color::Blue;

	sf::VideoMode* videoMode; 
	sf::RenderWindow* gameWindow;

	void setVideoMode();
	void onDestroy();

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