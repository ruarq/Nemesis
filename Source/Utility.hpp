#pragma once

#include <SFML/Graphics.hpp>

#include "Vec2.hpp"

void SetSpriteSize(sf::Sprite &sprite, const Vec2f &size);
Vec2f GetSpriteSize(const sf::Sprite &sprite);
Vec2f GetDefaultSpriteSize(const sf::Sprite &sprite);