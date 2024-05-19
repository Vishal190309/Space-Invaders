#pragma once
#include "SFML/Graphics.hpp"
#include "PlayerController.h"

class PlayerView {

private:
	const int playerSpriteWidth = 60;
	const int playerSpriteHeight = 60;
	const sf::String playerTexturePath = "assets/textures/player_ship.png";

	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	sf::RenderWindow* gameWindow;

	PlayerController* playerController;

	void initializePlayerSprite();
	void scalePlayerSprite();
public:
	PlayerView();
	~PlayerView();

	void initialize(PlayerController* controller);
	void update();
	void render();


	
};