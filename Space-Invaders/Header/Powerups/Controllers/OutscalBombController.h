#pragma once
#include "../../../Header/Powerups/PowerupController.h"

namespace Powerup
{
    namespace Controller
    {
        class OutscalBombController : public PowerupController
        {
        protected :
            void applyPowerup() override;
        public:
            OutscalBombController(PowerupType type);
            virtual ~OutscalBombController();
            
        };
    }
}