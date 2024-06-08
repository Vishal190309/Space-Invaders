#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>
#include "AnimationSystem.h"
namespace Animation {
	enum class AnimationType {
		EXPLOSION
	};
	class AnimationService {
	private:
		std::vector<AnimationSystem*> animations;
		std::vector<AnimationSystem*> flaggedAnimations;

		AnimationSystemConfig getAnimationSystemConfig(AnimationType type);
		void destroyFlaggedAnimationSystem();
		void destroy();

	public:
		AnimationService();
		~AnimationService();

		void initialize();
		void update();
		void render();

		void reset();
		void spawnAnimation(sf::Vector2f position, AnimationType type);
		void destroyAnimation(AnimationSystem* animationSystem);


	};
}