#pragma once
#include "../EnemyController.h"
#include "../../../Header/Powerups/PowerupConfig.h"
namespace Enemy {

	namespace Controllers {
		class UFOController : public EnemyController {
        private:
           
            void move() override;
            void moveLeft();
            void moveRight();
            void fireBullet() override;
            Powerup::PowerupType getRandomPowerupType();

        public:
            UFOController(EnemyType type, Entity::EntityType entityType);
            ~UFOController();

            void initialize() override;
		};
	}
}