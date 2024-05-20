#include "../../Header/Global/ServiceLocator.h"

namespace Global {
	using namespace Player;
	ServiceLocator::ServiceLocator()
	{
		graphicService = nullptr;
		eventService = nullptr;
		playerService = nullptr;
		timeService = nullptr;
		uiService = nullptr;
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
		uiService = new UIService();
	}

	void ServiceLocator::clearAllServices()
	{
		delete(graphicService);
		delete(eventService);
		delete(playerService);
		delete(timeService);
		delete(uiService);
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
		uiService->initialize();
	}

	void ServiceLocator::update()
	{
		graphicService->update();
		eventService->update();
		playerService->update();
		timeService->update();
		uiService->update();
	}

	void ServiceLocator::render()
	{
		graphicService->render();
		playerService->render();
		uiService->render();
		

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
	UIService* ServiceLocator::getUIService()
	{
		return uiService;
	}
}