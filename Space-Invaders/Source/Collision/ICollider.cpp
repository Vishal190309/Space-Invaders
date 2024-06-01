#include "../../Header/Collision/ICollider.h"

namespace Collision {

ICollider::ICollider()
{
	collisionState = CollisionState::ENABLED;
}

ICollider::~ICollider()
{
}

void ICollider::enableCollision()
{
	collisionState = CollisionState::ENABLED;
}

void ICollider::disableCollision()
{
	collisionState = CollisionState::DISABLED;
}

CollisionState ICollider::getCollisionState()
{
	return collisionState;
}

}

