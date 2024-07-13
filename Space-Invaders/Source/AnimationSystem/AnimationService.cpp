#include "../../Header/AnimationSystem/AnimationService.h"
#include "../../Header/AnimationSystem/AnimationSystemConfigData.h"

namespace Animation {
	AnimationSystemConfig AnimationService::getAnimationSystemConfig(AnimationType type)
	{
		switch (type)
		{
		case Animation::AnimationType::EXPLOSION:
			return explosionAnimationConfig;
		default:
			break;
		}
	}
	void AnimationService::destroyFlaggedAnimationSystem()
	{
		for (int i = 0; i < flaggedAnimations.size(); i++) {
			delete(flaggedAnimations[i]);
		}
		flaggedAnimations.clear();

	}
	void AnimationService::destroy()
	{

		for (int i = 0; i < animations.size(); i++) {
			delete(animations[i]);
		}
	}
	AnimationService::AnimationService()
	{
	}
	AnimationService::~AnimationService()
	{
		destroy();
	}
	void AnimationService::initialize()
	{
	}
	void AnimationService::update()
	{
		for (int i = 0; i < animations.size(); i++) {
			animations[i]->update();
		}
		destroyFlaggedAnimationSystem();
	}
	void AnimationService::render()
	{
		for (int i = 0; i < animations.size(); i++) {
			animations[i]->render();
		}
	}
	void AnimationService::reset()
	{
		destroy();
	}
	void AnimationService::spawnAnimation(sf::Vector2f position, AnimationType type)
	{
		AnimationSystem* animationSystem = new AnimationSystem(getAnimationSystemConfig(type));
		animationSystem->initialize(position);
		animations.push_back(animationSystem);
	}
	void AnimationService::destroyAnimation(AnimationSystem* animationSystem)
	{
		flaggedAnimations.push_back(animationSystem);
		animations.erase(std::find(animations.begin(), animations.end(), animationSystem), animations.end());
	}
}