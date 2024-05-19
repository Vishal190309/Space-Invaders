#include "../Header/ServiceLocator.h"

ServiceLocator::ServiceLocator()
{
	graphicService = nullptr;
	eventService = nullptr;
	playerService = nullptr;
	createServices();
}

ServiceLocator::~ServiceLocator()
{
	clearAllServices();
}

void ServiceLocator::createServices()
{
	graphicService = new GraphicService();
	eventService = new EventService();
	playerService = new PlayerService();
}

void ServiceLocator::clearAllServices()
{
	delete(graphicService);
	delete(eventService);
	delete(playerService);
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
}

void ServiceLocator::update()
{
	graphicService->update();
	eventService->update();
	playerService->update();
}

void ServiceLocator::render()
{
	graphicService->render();
	playerService->render();
}

EventService* ServiceLocator::getEventService()
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
