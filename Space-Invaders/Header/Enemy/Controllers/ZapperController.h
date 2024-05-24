#pragma once
#include "../EnemyController.h"
namespace Enemy {

	namespace Controllers {
		class ZapperController : public EnemyController {
        private:
            float verticalTravelDistance = 100.f;

            void move() override;
            void moveLeft();
            void moveRight();
            void moveDown();

        public:
            ZapperController(EnemyType type);
            ~ZapperController();

            void initialize() override;
		};
	}
}