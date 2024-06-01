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
	}
	void SoundService::playSound(SoundType soundType)
	{
		switch (soundType)
		{
		case SoundType::BUTTON_CLICK:
			soundEffect.setBuffer(bufferButtonClick);
			break;
		default:
			printf("Invalid Source Type");
			break;
		}

		soundEffect.play();
	}
	void SoundService::playBackroundMusic()
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