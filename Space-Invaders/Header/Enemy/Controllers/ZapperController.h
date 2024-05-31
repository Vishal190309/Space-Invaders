#pragma once
#include "../EnemyController.h"
#include "../../../Header/Bullet/BulletConfig.h"
namespace Enemy {

    namespace Controllers {
        class ZapperController : public EnemyController {
        private:
            float verticalTravelDistance = 100.f;
            float zapperFireRate = 2.f;
            void move() override;
            void moveLeft();
            void moveRight();
            void moveDown();
            void fireBullet() override;

        public:
            ZapperController(EnemyType type);
            ~ZapperController();

            void initialize() override;
        };
    }
}