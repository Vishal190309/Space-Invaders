#include "../../Header/Powerups/PowerupService.h"
#include "../../Header/Powerups/PowerupConfig.h"
#include "../../Header/Powerups/Controllers/ShieldController.h"
#include "../../Header/Powerups/Controllers/OutscalBombController.h"
#include "../../Header/Powerups/Controllers/RapidFireController.h"
#include "../../Header/Powerups/Controllers/TrippleLaserController.h"

namespace Powerup {
	PowerupController* PowerupService::createPowerup(PowerupType powerupType)
	{
		switch (powerupType)
		{
		case Powerup::PowerupType::SHIELD:
			return new Controller::ShieldController(powerupType);
			break;
		case Powerup::PowerupType::RAPID_FIRE:
			new Controller::RapidFireController(powerupType);
			break;
		case Powerup::PowerupType::TRIPPLE_LASER:
			new Controller::TrippleLaserController(powerupType);
			break;
		case Powerup::PowerupType::OUTSCAL_BOMB:
			new Controller::OutscalBombController(powerupType);
			break;
		
		}
		return new Controller::ShieldController(powerupType);
	}
	void PowerupService::destroy()
	{
		for (int i = 0; i < listOfPowerups.size(); i++) {
			delete(listOfPowerups[i]);
		}
	}
	PowerupService::PowerupService()
	{
		
	}
	PowerupService::~PowerupService()
	{
		destroy();
	}
	void PowerupService::initialize()
	{
		
	}
	void PowerupService::update()
	{
		for (int i = 0; i < listOfPowerups.size(); i++) {
			listOfPowerups[i]->update();
		}
	}
	void PowerupService::render()
	{
		for (int i = 0; i < listOfPowerups.size(); i++) {
			listOfPowerups[i]->render();
		}
	}
	PowerupController* PowerupService::spawnPowerup(PowerupType powerupType, sf::Vector2f position)
	{
		PowerupController* powerupController = createPowerup(powerupType);

		powerupController->initialize(position);
		listOfPowerups.push_back(powerupController);
		return powerupController;
	}
	void PowerupService::destroyPowerup(PowerupController* powerupController)
	{
		listOfPowerups.erase(std::remove(listOfPowerups.begin(), listOfPowerups.end(), powerupController), listOfPowerups.end());
		delete(powerupController);
	}
}