#include "UI.hpp"

namespace
{

sf::RenderWindow *uiWindow = nullptr;
sf::View uiView, prevView;

}

namespace UI
{

void Init(sf::RenderWindow &window)
{
	uiWindow = &window;
	uiView = _RenderWindow().getDefaultView();
}

sf::RenderWindow& _RenderWindow()
{
	return *uiWindow;
}

void BeginRender()
{
	prevView = _RenderWindow().getView();
	uiView.setSize(sf::Vector2f(_RenderWindow().getSize()));
	_RenderWindow().setView(uiView);
}

void EndRender()
{
	_RenderWindow().setView(prevView);
}

}