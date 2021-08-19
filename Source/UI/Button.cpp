#include "Button.hpp"

namespace UI
{

bool Button::is_hovered(const GameData &data) const
{
	return box.contains(sf::Vector2f(sf::Mouse::getPosition(data.window)));
}

bool Button::is_pressed(const GameData &data) const
{
	return this->is_hovered(data) && gInput->released(sf::Mouse::Left);
}

}