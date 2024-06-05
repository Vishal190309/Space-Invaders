#include "../../Header/Element/ElementService.h"
#include "../../Header/Element/Bunker/BunkerController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Collision/ICollider.h"

namespace Element {
	void ElementService::spawnBunkers()
	{
		for (int i = 0; i < bunkerDataList.size(); i++) {
			Bunker::BunkerController* bunkerController = new Bunker::BunkerController();
			bunkerController->initialize(bunkerDataList[i]);
			bunkerList.push_back(bunkerController);
			Global::ServiceLocator::getInstance()->getCollisionService()->addCollider(bunkerController);
			
		}
	}
	void ElementService::destroyFlaggedBunkerList()
	{
		for (int i = 0; i < flaggedBunkerList.size(); i++)
		{
			Global::ServiceLocator::getInstance()->getCollisionService()->removeCollider(dynamic_cast<Collision::ICollider*>(flaggedBunkerList[i]));
			delete (flaggedBunkerList[i]);
		}
		flaggedBunkerList.clear();
	}
	void ElementService::destroy()
	{
		for (int i = 0; i < flaggedBunkerList.size(); i++) {
			Global::ServiceLocator::getInstance()->getCollisionService()->removeCollider(dynamic_cast<Collision::ICollider*>(flaggedBunkerList[i]));
			delete(flaggedBunkerList[i]);
		}
		flaggedBunkerList.clear();
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
		spawnBunkers();
		
	}
	void ElementService::update()
	{
		for (int i = 0; i < bunkerList.size(); i++) {
			bunkerList[i]->update();
		}
		destroyFlaggedBunkerList();
	}
	void ElementService::render()
	{
		for (int i = 0; i < bunkerList.size(); i++) {
			bunkerList[i]->render();
		}
	}
	void ElementService::reset()
	{
		destroy();
	}
	void ElementService::destroyBunker(Bunker::BunkerController* bunkerController)
	{
		flaggedBunkerList.push_back(bunkerController);
		bunkerList.erase(std::remove(bunkerList.begin(), bunkerList.end(), bunkerController), bunkerList.end());
	}
}