#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/UI/UIElement/ImageView.h"

namespace Enemy {
	class EnemyController;
	enum class EnemyType;
	class EnemyView {
	private:
		
		const float enemyWidth = 50.f;
		const float enemyHeight = 50.f;

		UIElement::ImageView* enemyImage;
		EnemyController* enemyController;

		void createUIElemetns();
		void initializeImage();
		sf::String getEnemyTexturePath();
		void destroy();
	public:
		EnemyView();
		~EnemyView();

		void initialize(EnemyController* enemyController);
		void update();
		void render();
	};
}