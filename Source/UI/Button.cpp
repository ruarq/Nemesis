#include "Button.hpp"

namespace UI
{

bool Button::IsHovered(const GameData &data) const
{
	return box.contains(sf::Vector2f(sf::Mouse::getPosition(data.window)));
}

bool Button::IsPressed(const GameData &data) const
{
	return this->IsHovered(data) && Input::Released(sf::Mouse::Left);
}

}