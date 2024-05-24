
#pragma once
#include "../EnemyController.h"
namespace Enemy {

	namespace Controllers {
		class ThunderSnakeController : public EnemyController {
		private:
			float verticalMovmentSpeed = 25.f;
			float horizontalMovementSpeed = 300.f;
			void move() override;
			void moveLeft();
			void moveRight();

		public:
			ThunderSnakeController(EnemyType type);
			~ThunderSnakeController();
			void initialize() override;

		};
	}
}