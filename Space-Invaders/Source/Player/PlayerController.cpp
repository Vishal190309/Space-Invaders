#include "../../Header/Player/PlayerController.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Player/PlayerModel.h"
#include "../../Header/Player/PlayerView.h"
#include "../../Header/Bullet/BulletConfig.h"
#include "../../Header/Bullet/BulletController.h"
#include "../../Header/Entity/EntityConfig.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Powerups/PowerupController.h"

#include<algorithm>

namespace Player {
	
	
	PlayerController::PlayerController(Entity::EntityType entityType)
	{
		playerView = new PlayerView();
		playerModel = new PlayerModel(entityType);
		
	}

	PlayerController::~PlayerController()
	{
		delete(playerModel);
		delete(playerView);
	}

	void PlayerController::initialize()
	{
		playerModel->initialize();
		playerView->initialize(this);
	}

	void PlayerController::update()
	{
		switch (playerModel->getPlayerState())
		{
		case PlayerState::ALIVE:
			processPlayerInput();
			break;
		case PlayerState::FROZEN:
			updateFreezDuration();
			break;

		}
		updatePowerupDuration();
		updateFireDuration();
		playerView->update();
	}

	void PlayerController::render()
	{
		playerView->render();
	}

	void PlayerController::reset()
	{
		playerModel->reset();
	}

	void PlayerController::enableShield()
	{
		playerModel->elapsedShieldDuration = playerModel->shiledPowerupDuration;
		playerModel->setShieldState(true);
	}

	void PlayerController::enableRapidFire()
	{
		playerModel->elapsedRapidFireDuration = playerModel->rapidFirePowerupDuration;
		playerModel->setRapidFireState(true);
	}

	void PlayerController::enableTrippleLaser()
	{
		playerModel->elapsedTrippleLaserDuration = playerModel->trippleLaserPowerupDuration;
		playerModel->setTrippleLaserState(true);
	}

	void PlayerController::disableShield()
	{
		playerModel->setShieldState(false);
	}
	void PlayerController::disableRapidFire()
	{
		playerModel->setRapidFireState(false);
	}
	void PlayerController::disableTrippleLaser()
	{
		playerModel->setTrippleLaserState(false);
	}

	sf::Vector2f PlayerController::getPlayerPosition()
	{
		return playerModel->getPlayerPosition();
	}

	Entity::EntityType PlayerController::getEntityType()
	{
		return playerModel->getEntityType();
	}

	void PlayerController::processPlayerInput()
	{
		Event::EventService* eventService = Global::ServiceLocator::getInstance()->getEventService();
		// we will move this to event service at a later time
		if (eventService->pressedAKey() || eventService->pressedLeftKey())
		{
			moveLeft();
		}
		// we will move this to event service at a later time
		if (eventService->pressedDKey() || eventService->pressedRightKey())
		{
			moveRight();
		}
		if (eventService->pressedLeftMouseButton())
		{
			fireBullet();
		}
	}

	void PlayerController::moveLeft()
	{
		sf::Vector2f currentPosition = playerModel->getPlayerPosition();
		currentPosition.x -= playerModel->playerMovementSpeed * Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		currentPosition.x = std::max(currentPosition.x, playerModel->leftMostPosition.x);
		playerModel->setPlayerPosition(currentPosition);
	}

	void PlayerController::moveRight()
	{
		sf::Vector2f currentPosition = playerModel->getPlayerPosition();
		currentPosition.x += playerModel->playerMovementSpeed * Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		currentPosition.x = std::min(currentPosition.x, playerModel->rightMostPosition.x);
		playerModel->setPlayerPosition(currentPosition);
	}

	bool PlayerController::processBulletCollision(ICollider* otherCollider)
	{
		if (playerModel->isShieldEnabled()) return false;

		Bullet::BulletController* bulletController = dynamic_cast<Bullet::BulletController*>(otherCollider);

		if (bulletController && bulletController->getOwnerEntityType() != Entity::EntityType::PLAYER) {
			if (bulletController->getBulletType() == Bullet::BulletType::FROST_BULLET) {
				playerModel->setPlayerState(PlayerState::FROZEN);
				playerModel->elapsedFreezeDuration = playerModel->freezeDuration;
			}
			else {
				Global::ServiceLocator::getInstance()->getGameplayService()->restart();
			}
			return true;
		}
		return false;
	}

	bool PlayerController::processPowerupCollision(ICollider* otherCollider)
	{
		Powerup::PowerupController* powerup_controller = dynamic_cast<Powerup::PowerupController*>(otherCollider);
		if (powerup_controller)
		{
			return true;
		}
		return false;
	}

	bool PlayerController::processEnemyCollision(ICollider* otherCollider)
	{
		if (playerModel->isShieldEnabled())
			return false;

		Enemy::EnemyController* enemy_controller = dynamic_cast<Enemy::EnemyController*>(otherCollider);
		if (enemy_controller)
		{
			Global::ServiceLocator::getInstance()->getGameplayService()->restart();
			return true;
		}
		return false;
	}

	void PlayerController::updateFreezDuration()
	{
		if (playerModel->elapsedFreezeDuration > 0) {
			playerModel->elapsedFreezeDuration -= Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (playerModel->elapsedFreezeDuration <= 0) {
				playerModel->setPlayerState(PlayerState::ALIVE);
			}
		}
	}

	void PlayerController::freezPlayer()
	{
	}

	void PlayerController::updatePowerupDuration()
	{
		if (playerModel->elapsedShieldDuration > 0) {
			playerModel->elapsedShieldDuration -= Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
			if (playerModel->elapsedShieldDuration <= 0) {
				disableShield();
			}
		}

		if (playerModel->elapsedRapidFireDuration > 0) {
			playerModel->elapsedRapidFireDuration -= Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
			if (playerModel->elapsedRapidFireDuration <= 0) {
				disableRapidFire();
			}
		}

		if (playerModel->elapsedTrippleLaserDuration > 0) {
			playerModel->elapsedTrippleLaserDuration -= Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
			if (playerModel->elapsedTrippleLaserDuration <= 0) {
				disableTrippleLaser();
			}
		}
	}

	void PlayerController::updateFireDuration()
	{
		if (playerModel->elapsedFireDuration > 0) {
			playerModel->elapsedFireDuration -= Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		}
	}


	void PlayerController::fireBullet()
	{
		Global::ServiceLocator::getInstance()->getBulletService()->spawnBullet(Bullet::BulletType::LASER_BULLET,
			playerModel->getPlayerPosition() + playerModel->getPlayerBarrelOffset(),
			Bullet::MovementDirection::UP,playerModel->getEntityType());
	}

	const sf::Sprite& PlayerController::getColliderSprite()
	{
		return playerView->getPlayerSprite();
	}

	void PlayerController::onCollision(ICollider* otherCollider)
	{
		if (processPowerupCollision(otherCollider))
			return;

		if (processBulletCollision(otherCollider))
			return;

		processEnemyCollision(otherCollider);
	}

	

	void PlayerController::processBulletFire()
	{
		if (playerModel->elapsedFireDuration > 0) return;

		if (playerModel->isTrippleLaserEnabled())
		{
			fireBullet(true);
		}

		else 
		{
			fireBullet();
		}

		if (playerModel->isRapidFireEnabled())
		{
			playerModel->elapsedFireDuration = playerModel->rapidFireCooldownDuration;
		}

		else
		{
			playerModel->elapsedFireDuration = playerModel->fireCooldownDuration;
		}
	}

	void PlayerController::fireBullet(bool bTrippleLaser)
	{
		sf::Vector2f bulletPosition = playerModel->getPlayerPosition() + playerModel->barrelPositionOffset;
		fireBullet(bulletPosition);

		if (bTrippleLaser){
			fireBullet(bulletPosition + playerModel->secondWeaponPositionOffset);
			fireBullet(bulletPosition + playerModel->thirdWeaponPositionOffset);
		}
	}

	void PlayerController::fireBullet(sf::Vector2f position)
	{
		Global::ServiceLocator::getInstance()->getBulletService()->spawnBullet(Bullet::BulletType::LASER_BULLET
			, position, Bullet::MovementDirection::UP, playerModel->getEntityType());
	}

}

