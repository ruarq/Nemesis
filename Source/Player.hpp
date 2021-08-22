#pragma once

#include "Entity.hpp"
#include "World.hpp"

class Player final : public Entity
{
public:
	void Update(World &world) override;
	void Render(sf::RenderWindow &window) const override;
};