#pragma once
#include <vector>
#include "ICollider.h"
namespace Collision {
	class CollisionService {
	private:

		std::vector<ICollider*> listOfColliders;
		void processCollision();
		void doCollision(int indexI, int indexJ);
		bool hasCollisionOccurred(int indexI, int indexJ);
		bool areActiveColliders(int indexI, int indexJ);

	public:
		CollisionService();
		~CollisionService();

		void initialize();
		void update();
		void addCollider(ICollider* collider);
		void removeCollider(ICollider* collider);

	};
	

}