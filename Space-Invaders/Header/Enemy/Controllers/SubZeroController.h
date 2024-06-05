#pragma once
#include "../EnemyController.h"
namespace Enemy {

	namespace Controllers {
		class SubZeroController : public EnemyController {
		private:
			float verticalMovmentSpeed= 200.f;
			float subZeroFireRate = 1.5f;
			void move() override;
			void moveDown();
			void fireBullet() override;

		public:
			SubZeroController(EnemyType type, Entity::EntityType entityType);
			~SubZeroController();
			void initialize() override;

		};
	}
}