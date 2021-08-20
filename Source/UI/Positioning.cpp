#include "Positioning.hpp"

namespace UI
{

namespace Pos
{

sf::FloatRect Centered(const Vec2f &size, const Vec2f &offset)
{
	sf::FloatRect centeredRect;
	const Vec2f window_size = _RenderWindow().getSize();

	centeredRect.left = window_size.x / 2.0f - size.x / 2.0f + offset.x;
	centeredRect.top = window_size.y / 2.0f - size.y / 2.0f + offset.y;
	centeredRect.width = size.x;
	centeredRect.height = size.y;
	
	return centeredRect;
}

}

}