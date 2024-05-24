#pragma once
#include "../EnemyController.h"
namespace Enemy {

	namespace Controllers {
		class SubZeroController : public EnemyController {
		private:
			float verticalMovmentSpeed= 100.f;
			void move() override;
			void moveDown();

		public:
			SubZeroController();
			~SubZeroController();
			void initialize() override;

		};
	}
}