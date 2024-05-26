#pragma once
#include "../../Header/Graphic/GraphicService.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/Player/PlayerService.h"
#include "../Time/TimeService.h"
#include "../UI/UIService.h"
#include "../Enemy/EnemyService.h"
#include "../../Header/Gameplay/GameplayService.h"
#include "../../Header/Element/ElementService.h"
#include "../../Header/Sound/SoundService.h"
#include "../../Header/Bullet/BulletService.h"

// ServiceLocator Class Summary: This class manages access to various services in the application.
// include relevant headers files

namespace Global {
    using namespace Graphic;
    using namespace Player;
    using namespace Time;
    using namespace UI;
    using namespace Enemy;
    using namespace Bullet;
    using namespace Gameplay;
    using namespace Element;
    using namespace Sound;
    class ServiceLocator
    {
    private:
        // Private Attributes:
        // - event_service: Manages event-related functionalities.
        GraphicService* graphicService;
        Event::EventService* eventService;
        GameplayService* gameplayService;
        PlayerService* playerService;
        ElementService* elementService;
        EnemyService* enemyService;
        BulletService* bulletService;
        TimeService* timeService;
        UIService* uiService;
        SoundService* soundService;
       
        // ..........................
        // ..........................

        // Private Constructor and Destructor:

      // Constructor for initializing the ServiceLocator.
        ServiceLocator();

        // Destructor for cleaning up resources upon object deletion.
        ~ServiceLocator();

        // Private Methods:
        void createServices(); 			// Creates instances of all services.
        void clearAllServices(); 		//	Deletes and deallocates memory for all services.

    public:


        // Public Methods:
        static ServiceLocator* getInstance();  // Provides a method to access the unique ServiceLocator instance (object). We will discuss this later.

        void initialize(); 			//	Initializes the ServiceLocator.
        void update(); 				//	Updates all services.
        void render(); 				//	Renders using the services.

        // Methods to Get Specific Services: 
        Event::EventService* getEventService();   // Retrieve the EventService instance
        GraphicService* getGraphicService();
        GameplayService* getGameplayService();
        PlayerService* getPlayerService();
        ElementService* getElementService();
        EnemyService* getEnemyService();
        BulletService* getBulletService();
        TimeService* getTimeService();
        UIService* getUIService();
        SoundService* getSoundService();
       

    };
}