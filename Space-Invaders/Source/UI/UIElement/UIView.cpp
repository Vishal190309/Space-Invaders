#include "../../../Header/UI/UIElement/UIView.h"
#include "../../../Header/Global/ServiceLocator.h"

namespace UIElement {
	UIView::UIView()
	{
	}
	UIView::~UIView()
	{
	}
	void UIView::initialize()
	{
		gameWindow = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		uiState = UIState::VISIBLE;
	}
	void UIView::update()
	{
	}
	void UIView::render()
	{
	}
	void UIView::show()
	{
		uiState = UIState::VISIBLE;
	}
	void UIView::hide()
	{
		uiState = UIState::HIDDEN;
	}
}