#pragma once
#include <SFML/Graphics.hpp>

namespace Global
{
	class Config
	{
	public:
		static const std::string gameWindowTitle;
		static const sf::String outscalLogoTexturePath;
		static const sf::String backgroundTexturePath;
		static const sf::String playerTexturePath;

		static const sf::String zapperTexturePath;
		static const sf::String thunderSnakeTexturePath;
		static const sf::String subzeroTexturePath;
		static const sf::String ufoTexturePath;
		static const sf::String bunkerTexturePath;

		static const sf::String shieldTexturePath;
		static const sf::String trippleLaserTexturePath;
		static const sf::String rapidFireTexturePath;
		static const sf::String outscalBombTexturePath;

		static const sf::String laserBulletTexturePath;
		static const sf::String torpedoeTexturePath;
		static const sf::String frostBeamTexturePath;

		static const sf::String playButtonTexturePath;
		static const sf::String instructionsButtonTexturePath;
		static const sf::String quitButtonTexturePath;
		static const sf::String menuButtonTexturePath;

		static const sf::String bubbleBobbleFontPath;
		static const sf::String DS_DIGIBFontPath;

		static const sf::String backgroundMusicPath;
		static const sf::String buttonClickSoundPath;
	};
}