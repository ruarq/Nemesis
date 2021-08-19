#include "Positioning.hpp"

namespace UI
{

namespace Pos
{

sf::FloatRect centered(const GameData &data, const Vec2f &size, const Vec2f &offset)
{
	sf::FloatRect centered_rect;
	const Vec2f window_size = data.window.getSize();

	centered_rect.left = window_size.x / 2.0f - size.x / 2.0f + offset.x;
	centered_rect.top = window_size.y / 2.0f - size.y / 2.0f + offset.y;
	centered_rect.width = size.x;
	centered_rect.height = size.y;
	
	return centered_rect;
}

}

}