#include "../../Header/Main/GameService.h"
#include "../../Header/Graphic/GraphicService.h"

namespace Main {
	void GameService::initialize()
	{

		serviceLocator->initialize();
		initializeVariable();

	}

	void GameService::initializeVariable()
	{
		gameWindow = serviceLocator->getGraphicService()->getGameWindow();
	}

	void GameService::destroy()
	{
	}

	// Constructor: Initializes pointers to null.
	GameService::GameService() {
		serviceLocator = nullptr; // Set service locator to null
		gameWindow = nullptr; // Set game window to null
	}

	// Destructor: Calls the destroy function to clean up resources.
	GameService::~GameService() {
		destroy(); // Clean up and release resources
	}

	// Prepares the game service for use by obtaining the service locator instance and initializing services.
	void GameService::ignite() {
		serviceLocator = Global::ServiceLocator::getInstance(); // Get ServiceLocator
		initialize(); // Initialize services.
	}

	// Updates the game logic by delegating to the service locator's update method.
	void GameService::update() {

		// Process Events.
		serviceLocator->getEventService()->processEvents();

		// Update Game Logic.
		serviceLocator->update();// Call update on the service locator which then updates all its managed services
	}

	// Clears the window then display it.
	void GameService::render() {
		// Clears the game window with the background color provided by the graphic service
		gameWindow->clear(serviceLocator->getGraphicService()->getWindowColor());
		serviceLocator->render();
		gameWindow->display();
		// Render the current frame using the service locator
		 // Display the rendered frame on the game window
	}

	// Checks if the game is still running by querying the graphic service's window open status.
	bool GameService::isRunning() {
		// Returns true if the game window is open, indicating the game is still running
		return serviceLocator->getGraphicService()->isGameWindowOpen();
	}
}