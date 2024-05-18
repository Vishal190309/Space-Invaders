#pragma once
#include "ServiceLocator.h"
#include "SFML/Graphics.hpp"

class GameService {
private:
	ServiceLocator* serviceLocator;
	sf::RenderWindow* gameWindow;
	void initialize();
	void initializeVariable();
	void destroy();

public:
	GameService();

	~GameService();
	void ignite();
	void update() ;
	void render() ;
	bool isRunning() ;
	
};