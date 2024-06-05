#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>
#include "../../header/Element/Bunker/BunkerController.h"
#include "../../header/Element/Bunker/BunkerModel.h"

namespace Element
{
	class BunkerController;

	class ElementService
	{
	private:
		//const vector so that the default values will not be changed down the road by mistake.
		const std::vector<Bunker::BunkerData> bunkerDataList = { Bunker::BunkerData(sf::Vector2f(130.f, 800.f)),
																Bunker::BunkerData(sf::Vector2f(430.0f, 800.f)),
																Bunker::BunkerData(sf::Vector2f(730.0f, 800.f)),
																Bunker::BunkerData(sf::Vector2f(1130.0f, 800.f)),
																Bunker::BunkerData(sf::Vector2f(1430.0f, 800.f)),
																Bunker::BunkerData(sf::Vector2f(1730.0f, 800.f)) };

		std::vector<Bunker::BunkerController*> bunkerList;
		std::vector<Bunker::BunkerController*> flaggedBunkerList;

		void spawnBunkers();
		void destroyFlaggedBunkerList();
		void destroy();

	public:
		ElementService();
		virtual ~ElementService();

		void initialize();
		void update();
		void render();
		void reset();

		void destroyBunker(Bunker::BunkerController* bunkerController);
	};
}