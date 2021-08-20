#pragma once

#include <SFML/Graphics.hpp>

#include "../GameData.hpp"
#include "../Vec2.hpp"

namespace UI
{

namespace Pos
{

/**
 * @brief get a rect centered in the data.window window.
 */
sf::FloatRect Centered(const GameData &data, const Vec2f &size, const Vec2f &offset = Vec2f());

}

}