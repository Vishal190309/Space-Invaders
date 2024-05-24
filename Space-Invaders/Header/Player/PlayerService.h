#pragma once

#include <SFML/Graphics.hpp>
#include "../../Header/Event/EventService.h"

namespace Player {
	class PlayerController;

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
}
