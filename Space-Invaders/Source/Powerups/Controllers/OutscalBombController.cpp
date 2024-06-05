#include "../../../Header/Powerups/Controllers/OutscalBombController.h"
#include "../../../Header/Global/ServiceLocator.h"

namespace Powerup
{
    namespace Controller
    {
        OutscalBombController::OutscalBombController(PowerupType type) : PowerupController(type) {}

        OutscalBombController::~OutscalBombController() {}

        void OutscalBombController::applyPowerup()
        {
            Global::ServiceLocator::getInstance()->getEnemyService()->reset();
        }
        
    }
}