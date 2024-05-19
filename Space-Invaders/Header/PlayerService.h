#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "EventService.h"

class PlayerService {

private:
	int playerScore = 0;
	int health = 100;
	float movementSpeed = 350.0f;
	sf::Vector2f position = sf::Vector2f(200, 100);
	const sf::String texturePath= "assets/textures/player_ship.png";
	sf::RenderWindow* gameWindow;
	EventService* eventService;
	sf::Texture playerTexture;
	sf::Sprite playerSprite;

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
