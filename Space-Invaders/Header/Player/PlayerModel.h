#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Entity/EntityConfig.h"

namespace Player {
    enum class PlayerState //Our Enum
    {
        ALIVE,
        FROZEN,
        DEAD,
        // we will add more states later
    };

    class PlayerModel
    {
    private:
        const sf::Vector2f initialPlayerPosition = sf::Vector2f(950.f, 950.f);

        sf::Vector2f playerPosition;
        PlayerState playerState;
        int playerScore;
        Entity::EntityType entityType;

        bool bShield;
        bool bRapidFire;
        bool bTrippleLaser;
    public:
        const sf::Vector2f leftMostPosition = sf::Vector2f(50.f, 950.f);
        const sf::Vector2f rightMostPosition = sf::Vector2f(1800.f, 950.f);
        const sf::Vector2f barrelPositionOffset = sf::Vector2f(20.f, 5.f);
        const sf::Vector2f secondWeaponPositionOffset = sf::Vector2f(45.f, 0.f);
        const sf::Vector2f thirdWeaponPositionOffset = sf::Vector2f(-45.f, 0.f);

        const float shiledPowerupDuration = 10.f;
        const float rapidFirePowerupDuration = 10.f;
        const float trippleLaserPowerupDuration = 10.f;

        const float freezeDuration = 2.f;

        const float fireCooldownDuration = 0.2f;
        const float rapidFireCooldownDuration = 0.05f;
        const float trippleLaserPositionOffset = 30.f;

        float elapsedShieldDuration;
        float elapsedRapid_fireDuration;
        float elapsedTripple_laserDuration;

        float elapsedFireDuration;
        float elapsedFreezeDuration;

        const float playerMovementSpeed =350.0f;

        PlayerModel(Entity::EntityType entityType);
        ~PlayerModel();

        void initialize();
        void reset();
     

        sf::Vector2f getPlayerPosition();
        void setPlayerPosition(sf::Vector2f position);

        int getPlayerScore();
        void setPlayerScore(int score);

        //new getter and setter
        PlayerState getPlayerState();
        void setPlayerState(PlayerState state);

        Entity::EntityType getEntityType();


        bool isShieldEnabled();
        bool isRapidFireEnabled();
        bool isTrippleLaserEnabled();

        void setShieldState(bool value);
        void setRapidFireState(bool value);
        void setTrippleFireState(bool value);

    };
}