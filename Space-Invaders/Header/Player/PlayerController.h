#pragma once
#include "PlayerModel.h"
#include "PlayerView.h"
#include <SFML/Graphics.hpp>

class PlayerController {

private:
	PlayerView* playerView;
	PlayerModel* playerModel;

	void processPlayerInput();
	void moveLeft();
	void moveRight();

public:
	PlayerController();
	~PlayerController();

	void initialize();
	void update();
	void render();

	sf::Vector2f getPlayerPosition();

};
