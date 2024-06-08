#pragma once
#include "AnimationSystemConfig.h"
#include "../UI/UIElement/ImageView.h"
namespace Animation {
	class AnimationSystem {
	private:
		AnimationSystemConfig animationSystemConfig;
		sf::Vector2f animationPosition;

		UI::UIElement::ImageView* animationImage;
		sf::Clock clock;
		sf::Time frameTime;
		int currentFrame;

		void createUIElemets();
		void initializeImage();

	public:
		AnimationSystem(AnimationSystemConfig animtionConfig);
		~AnimationSystem();

		void initialize(sf::Vector2f position);
		void update();
		void render();
		void destroy();

	};
}
