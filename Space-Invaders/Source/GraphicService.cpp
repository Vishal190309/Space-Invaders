#include "../Header/GraphicService.h"

void GraphicService::setVideoMode()
{
	videoMode = new sf::VideoMode(game_window_width, game_window_height, sf::VideoMode::getDesktopMode().bitsPerPixel);
}

void GraphicService::onDestroy()
{
	delete(gameWindow);
	delete(videoMode);
}

GraphicService::GraphicService()
{
	gameWindow = nullptr;
	videoMode = nullptr;
}

GraphicService::~GraphicService()
{
	onDestroy();

}

sf::RenderWindow* GraphicService::createGameWindow()
{
	setVideoMode();
	return new sf::RenderWindow(*videoMode,game_window_title);
}

void GraphicService::initialize()
{
	gameWindow = createGameWindow();

}

void GraphicService::update() {
}

void GraphicService::render() {
}

bool GraphicService::isGameWindowOpen() {
	return gameWindow->isOpen();
}

sf::RenderWindow* GraphicService::getGameWindow() {
	return gameWindow;
}

sf::Color GraphicService::getWindowColor() {
	return windowColor;
}


