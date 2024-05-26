#pragma once
#include <SFML/Graphics.hpp>

namespace Player {
    enum class PlayerState //Our Enum
    {
        ALIVE,
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
        const sf::Vector2f barrelPositionOffset = sf::Vector2f(20.f, -25.f);
    public:
        const sf::Vector2f leftMostPosition = sf::Vector2f(50.f, 950.f);
        const sf::Vector2f rightMostPosition = sf::Vector2f(1800.f, 950.f);

        const float playerMovementSpeed =350.0f;

        PlayerModel();
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

        sf::Vector2f getPlayerBarrelOffset();




    };
}