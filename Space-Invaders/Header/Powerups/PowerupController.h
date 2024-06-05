#pragma once
#include "../../Header/Collectible/ICollectible.h"
#include "../../Header/Collision/ICollider.h"
namespace Powerup {
	enum class PowerupType;
	class PowerupModel;
	class PowerupView;
	class PowerupController : public Collision::ICollider, public Collectible::ICollectible  {
	protected:
		PowerupModel* powerupModel;
		PowerupView* powerupView;

		virtual void applyPowerup() = 0;

		void updatePowerupPosition();
		void handleOutOfBounds();

	public:
		PowerupController(PowerupType type);
		virtual ~PowerupController();
		void initialize(sf::Vector2f position) override;
		void update() override;
		void render() override;

		void onCollected() override;
		sf::Vector2f  getPowerupPosition() override;
		PowerupType getPowerupType();

		const sf::Sprite& getColliderSprite() override;
		void onCollision(ICollider* otherCollider) override;

		



	};
}