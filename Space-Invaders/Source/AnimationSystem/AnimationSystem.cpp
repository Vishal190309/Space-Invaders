#include "../../Header/AnimationSystem/AnimationSystem.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Animation {
	void AnimationSystem::createUIElemets()
	{
		animationImage = new UI::UIElement::ImageView();
	}
	void AnimationSystem::initializeImage()
	{
		animationImage->initialize(Global::Config::explostionTexturePath,0,0,animationPosition);
		animationImage->setTextureRect(sf::IntRect(0, 0, animationSystemConfig.tileWidth, animationSystemConfig.tileHeight));
		animationImage->setScale(animationSystemConfig.spriteSheetWidth, animationSystemConfig.spriteSheetHeight, animationSystemConfig.tileWidth, animationSystemConfig.tileHeight);
	}
	AnimationSystem::AnimationSystem(AnimationSystemConfig animtionConfig)
	{
		animationSystemConfig = animtionConfig;
		createUIElemets();
	}
	AnimationSystem::~AnimationSystem()
	{
		delete(animationImage);
	}
	void AnimationSystem::initialize(sf::Vector2f position)
	{
		animationPosition = position;
		currentFrame = 0;
		frameTime = sf::seconds(animationSystemConfig.frameDuration);
		initializeImage();
	}
	void AnimationSystem::update()
	{
		if (clock.getElapsedTime() >= frameTime) {
			if (currentFrame + 1 >= animationSystemConfig.numberOfAnimationFrames)
				destroy();

			currentFrame = (currentFrame + 1) % animationSystemConfig.numberOfAnimationFrames;
			clock.restart();

			animationImage->setTextureRect(sf::IntRect(
				currentFrame * animationSystemConfig.tileWidth,
				0,
				animationSystemConfig.tileWidth,
				animationSystemConfig.tileHeight
			));
			animationImage->update();
		}
	}
	void AnimationSystem::render()
	{
		animationImage->render();
	}
	void AnimationSystem::destroy()
	{
		Global::ServiceLocator::getInstance()->getAnimationService()->destroyAnimation(this);
	}
}