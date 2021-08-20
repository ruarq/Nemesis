#include "Button.hpp"

namespace UI
{

bool Button::IsHovered() const
{
	return box.contains(sf::Vector2f(sf::Mouse::getPosition(_RenderWindow())));
}

bool Button::IsPressed() const
{
	return this->IsHovered() && Input::Released(sf::Mouse::Left);
}

}