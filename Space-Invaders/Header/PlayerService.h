#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "EventService.h"

class PlayerService {

private:
	
	const sf::String texturePath= "assets/textures/player_ship.png";
	sf::RenderWindow* gameWindow;
	EventService* eventService;
	

	void initializePlayerSprite();
	void ProcessPlayerInput();
	void moveLeft();
	void moveRight();

public:

	PlayerService();
	~PlayerService();

	void initialize();
	void update();
	void render();

	int getMoveSpeed();
	sf::Vector2f getPosition();
};
