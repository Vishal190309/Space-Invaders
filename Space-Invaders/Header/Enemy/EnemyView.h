#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Enemy/EnemyConfig.h"
namespace Enemy {
	class EnemyController;
	class EnemyView {
	private:
		const sf::String subzeroTexturePath = "assets/textures/subzero.png";
		const sf::String zapperTexturePath = "assets/textures/zapper.png";
		const float enemyWidth = 50.f;
		const float enemyHeight = 50.f;

		sf::Texture enemyTexture;
		sf::Sprite enemySprite;

		EnemyController* enemyController;
		sf::RenderWindow* gameWindow;
		void initializeSprite(EnemyType type);
		void scaleSprite();
	public:
		EnemyView();
		~EnemyView();

		void initialize(EnemyController* enemyController);
		void update();
		void render();
	};
}