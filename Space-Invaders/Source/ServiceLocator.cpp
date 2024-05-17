#include "../Header/ServiceLocator.h"

ServiceLocator::ServiceLocator()
{
	graphicService = nullptr;
	eventService = nullptr;
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
}

void ServiceLocator::clearAllServices()
{
	delete(graphicService);
	delete(eventService);
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
}

void ServiceLocator::update()
{
	graphicService->update();
	eventService->update();
}

void ServiceLocator::render()
{
	graphicService->render();
}

EventService* ServiceLocator::getEventService()
{
	return eventService;
}

GraphicService* ServiceLocator::getGraphicService()
{
	return graphicService;
}
