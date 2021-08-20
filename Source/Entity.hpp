#pragma once

#include <memory>

#include <SFML/Graphics.hpp>

#include "Vec2.hpp"

class World;

class Entity
{
public:
	using Ptr = std::shared_ptr<Entity>;

public:
	virtual void Update(World &world) = 0;
	virtual void Render(sf::RenderWindow &window) const = 0;

public:
	Vec2f pos;
};