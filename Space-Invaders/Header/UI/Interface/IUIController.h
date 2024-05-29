#pragma once

namespace UI {
	namespace Inteface {
		class IUIController {
		public:

			virtual void initialize()=0;
			virtual void update()=0;
			virtual void render()=0;

			virtual ~IUIController() {};
		};
	}
}