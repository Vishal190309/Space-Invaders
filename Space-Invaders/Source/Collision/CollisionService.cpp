#include "../../Header/Collision/CollisionService.h"

namespace Collsion {

}

void Collision::CollisionService::processCollision()
{
	for (int i = 0; i < listOfColliders.size(); i++)
	{
		for (int j = i + 1; j < listOfColliders.size(); j++)
		{
			doCollision(i, j);
		}
	}
}

void Collision::CollisionService::doCollision(int indexI, int indexJ)
{
	if (listOfColliders[indexI]->getCollisionState() == CollisionState::DISABLED ||
		listOfColliders[indexJ]->getCollisionState() == CollisionState::DISABLED) return;

	if (hasCollisionOccurred(indexI, indexJ))
	{
		if (areActiveColliders(indexI, indexJ))
			listOfColliders[indexI]->onCollision(listOfColliders[indexJ]);

		if (areActiveColliders(indexI, indexJ))
			listOfColliders[indexJ]->onCollision(listOfColliders[indexI]);
	}
}

bool Collision::CollisionService::hasCollisionOccurred(int indexI, int indexJ)
{
	const sf::Sprite& collider_one_sprite = listOfColliders[indexI]->getColliderSprite();
	const sf::Sprite& collider_two_sprite = listOfColliders[indexJ]->getColliderSprite();

	return collider_one_sprite.getGlobalBounds().intersects(collider_two_sprite.getGlobalBounds());
}

bool Collision::CollisionService::areActiveColliders(int indexI, int indexJ)
{
	return (indexI < listOfColliders.size() && indexJ < listOfColliders.size() &&
		listOfColliders[indexI] != nullptr && listOfColliders[indexJ] != nullptr);
}

Collision::CollisionService::CollisionService()
{
}

Collision::CollisionService::~CollisionService()
{
}

void Collision::CollisionService::initialize()
{
}

void Collision::CollisionService::update()
{
	processCollision();
}

void Collision::CollisionService::addCollider(ICollider* collider)
{
	listOfColliders.push_back(collider);
}

void Collision::CollisionService::removeCollider(ICollider* collider)
{
	listOfColliders.erase(std::remove(listOfColliders.begin(), listOfColliders.end(), collider), listOfColliders.end());
}
