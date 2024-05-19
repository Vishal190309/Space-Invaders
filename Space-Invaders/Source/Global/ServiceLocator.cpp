#include "../../Header/Global/ServiceLocator.h"

namespace Global {
	using namespace Player;
	ServiceLocator::ServiceLocator()
	{
		graphicService = nullptr;
		eventService = nullptr;
		playerService = nullptr;
		timeService = nullptr;
		createServices();
	}

	ServiceLocator::~ServiceLocator()
	{
		clearAllServices();
	}

	void ServiceLocator::createServices()
	{
		graphicService = new GraphicService();
		eventService = new Event::EventService();
		playerService = new PlayerService();
		timeService = new TimeService();
	}

	void ServiceLocator::clearAllServices()
	{
		delete(graphicService);
		delete(eventService);
		delete(playerService);
		delete(timeService);
	}

	ServiceLocator* ServiceLocator::getInstance()
	{
		static ServiceLocator instance;
		return &instance;
	}

	void ServiceLocator::initialize()
	{
		graphicService->initialize();
		eventService->initialize();
		playerService->initialize();
		timeService->initialize();
	}

	void ServiceLocator::update()
	{
		graphicService->update();
		eventService->update();
		playerService->update();
		timeService->update();
	}

	void ServiceLocator::render()
	{
		graphicService->render();
		playerService->render();

	}

	Event::EventService* ServiceLocator::getEventService()
	{
		return eventService;
	}

	GraphicService* ServiceLocator::getGraphicService()
	{
		return graphicService;
	}

	PlayerService* ServiceLocator::getPlayerService()
	{
		return playerService;
	}

	TimeService* ServiceLocator::getTimeService()
	{
		return timeService;
	}
}