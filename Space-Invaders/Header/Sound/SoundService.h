#pragma once
#include<SFML/Audio.hpp>
namespace Sound {
	enum class SoundType {
		BUTTON_CLICK,
		BULLET_FIRE,
		EXPLOSION,
		POWERUP_ENABLED,
		POWERUP_DISABLED,
	};
	class SoundService {
	private:
		const int volume = 30;


		sf::Music backgroundMusic;
		sf::Sound soundEffect;
		sf::Sound powerupSoundEffect;

		sf::SoundBuffer bufferButtonClick;

		sf::SoundBuffer bufferBulletFire;

		sf::SoundBuffer bufferPowerupEnabled;
		sf::SoundBuffer bufferPowerupDisabled;
		void loadBackgroundMusicFromFile();
		void loadSoundFromFile();

	public:
		void playSound(SoundType);
		void playBackgroundMusic();
		void initialize();

	};
}