#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "EventService.h"
#include "Player\PlayerController.h"

class PlayerService {

private:
	
	
	PlayerController* playerController;

public:

	PlayerService();
	~PlayerService();

	void initialize();
	void update();
	void render();

};
