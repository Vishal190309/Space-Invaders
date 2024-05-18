#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Header/GameService.h"

//class Player {
//    
//private:
//    int playerScore=0;
//    int health=100;
//    int movementSpeed=1;
//    sf::Vector2f position= sf::Vector2f(200,100);
//
//public:
//
//    sf::Texture playerTexture;
//    sf::Sprite playerSprite;
//
//    int getScore() {
//        return playerScore;
//    }
//    int getMoveSpeed() {
//        return movementSpeed;
//    }
//
//    sf::Vector2f getPosition() {
//        return position;
//    }
//
//    void setScore(int newScore) {
//        this->playerScore = newScore;
//    }
//
//    void takeDamage() {
//
//    }
//
//    void move(int offsetX) {
//        position.x += offsetX;
//    }
//
//    void shootBullets() {
//
//    }
//};


int main()
{
    //sf::VideoMode videoMode = *(new sf::VideoMode(800, 600));

    //sf::RenderWindow window(videoMode, "My SFML Window");
    //Player player;
    //player.playerTexture.loadFromFile("assets/textures/player_ship.png");
    //player.playerSprite.setTexture(player.playerTexture);


    //while (window.isOpen())
    //{
    //    sf::Event event;
    //    while (window.pollEvent(event)) {
    //        // Check for window closure
    //        if (event.type == sf::Event::Closed)
    //            window.close();
    //    }

    //   
    //  
    //   
    //    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    //        player.move(-1.0f*player.getMoveSpeed());
    //    }

    //    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    //        player.move(1.0f* player.getMoveSpeed());
    //    }
    //    // Clear the window
    //    window.clear(sf::Color::Blue);
    //    // Draw your content here...
    //    player.playerSprite.setPosition(player.getPosition());
    //    window.draw(player.playerSprite);

    //    // Display what was drawn
    //    window.display();
    //}


    GameService* game_service = new GameService();

    game_service->ignite();

    while (game_service->isRunning())
    {
        game_service->update();
        game_service->render();
    }

}