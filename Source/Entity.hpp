#pragma once

#include <string>

#include <SFML/Graphics.hpp>

#include "Types.hpp"
#include "Vec2.hpp"

class World;

class Entity
{
public:
	explicit Entity(const EntityId id);
	virtual ~Entity() = default;

public:
	virtual void Update(World &world) = 0;
	virtual void Render(sf::RenderWindow &window) const = 0;

public:
	const EntityId id;
	std::string name;
	Vec2f pos;
	bool alive = true;
};