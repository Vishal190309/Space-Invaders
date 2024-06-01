
#pragma once
#include "../EnemyController.h"
namespace Enemy {

	namespace Controllers {
		class ThunderSnakeController : public EnemyController {
		private:
			float verticalMovmentSpeed = 25.f;
			float horizontalMovementSpeed = 300.f;
			float thunderSnakeFireRate = 3.f;
			void move() override;
			void moveLeft();
			void moveRight();
			void fireBullet() override;

		public:
			ThunderSnakeController(EnemyType type, Entity::EntityType entityType);
			~ThunderSnakeController();
			void initialize() override;

		};
	}
}