#pragma once
#include<SFML/Audio.hpp>
namespace Sound {
	enum class SoundType {
		BUTTON_CLICK,
	};
	class SoundService {
	private:
		const int volume = 30;


		sf::Music backgroundMusic;
		sf::Sound soundEffect;
		sf::SoundBuffer bufferButtonClick;
		void loadBackgroundMusicFromFile();
		void loadSoundFromFile();

	public:
		void playSound(SoundType);
		void playBackroundMusic();
		void initialize();

	};
}