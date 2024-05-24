#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy {
	class EnemyController;
	enum class EnemyType;
	class EnemyView {
	private:
		
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