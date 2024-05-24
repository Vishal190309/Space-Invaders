#include "../../Header/Element/ElementService.h"
#include "../../Header/Element/Bunker/BunkerController.h"

namespace Element {
	void ElementService::destroy()
	{
		for (int i = 0; i < bunkerList.size(); i++) {
			delete(bunkerList[i]);
		}
	}
	Element::ElementService::ElementService()
	{

	}
	ElementService::~ElementService()
	{
		destroy();
	}
	void ElementService::initialize()
	{
		for (int i = 0; i < bunkerDataList.size(); i++) {
			Bunker::BunkerController* bunkerController = new Bunker::BunkerController();
			bunkerController->initialize(bunkerDataList[i]);
			bunkerList.push_back(bunkerController);
		}
	}
	void ElementService::update()
	{
		for (int i = 0; i < bunkerList.size(); i++) {
			bunkerList[i]->update();
		}
	}
	void ElementService::render()
	{
		for (int i = 0; i < bunkerList.size(); i++) {
			bunkerList[i]->render();
		}
	}
}