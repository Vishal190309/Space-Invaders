#include "../../Header/Sound/SoundService.h"
#include "../../Header/Global/Config.h"

namespace Sound {
	using namespace Global;
	void SoundService::loadBackgroundMusicFromFile()
	{
		if (!backgroundMusic.openFromFile(Config::backgroundMusicPath)) {
			printf("Error loading background music file");
		}
	}
	void SoundService::loadSoundFromFile()
	{
		if (!bufferButtonClick.loadFromFile(Config::buttonClickSoundPath)) {
			printf("Error loading button click file");
		}
		if (!bufferBulletFire.loadFromFile(Config::bulletFireSoundPath)) {
			printf("Error loading button click file");
		}
		if (!bufferPowerupEnabled.loadFromFile(Config::powerupEnabledSoundPath)) {
			printf("Error loading button click file");
		}
		if (!bufferPowerupDisabled.loadFromFile(Config::powerupDisabledSoundPath)) {
			printf("Error loading button click file");
		}
		
	}
	void SoundService::playSound(SoundType soundType)
	{
		switch (soundType)
		{
		case SoundType::BUTTON_CLICK:
			soundEffect.setBuffer(bufferButtonClick);
			soundEffect.play();
			break;
		case SoundType::BULLET_FIRE:
			soundEffect.setBuffer(bufferBulletFire);
			soundEffect.play();
			break;
		case SoundType::POWERUP_ENABLED:
			powerupSoundEffect.setBuffer(bufferPowerupEnabled);
			powerupSoundEffect.play();
			break;
		case SoundType::POWERUP_DISABLED:
			powerupSoundEffect.setBuffer(bufferPowerupDisabled);
			powerupSoundEffect.play();
			break;
		default:
			printf("Invalid Source Type");
			break;
		}

		
	}
	void SoundService::playBackgroundMusic()
	{
		
			backgroundMusic.setVolume(volume);
			backgroundMusic.setLoop(true);
			backgroundMusic.play();
		
	}
	void SoundService::initialize()
	{
		loadBackgroundMusicFromFile();
		loadSoundFromFile();
	}
}