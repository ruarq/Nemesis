#pragma once

#include "TextureManager.hpp"
#include "Entity.hpp"
#include "World.hpp"
#include "Time.hpp"
#include "Data.hpp"
#include "Utility.hpp"

class Player final : public Entity
{
public:
	void Create() override;
	void Update(World &world) override;
	void Render(sf::RenderWindow &window) override;

public:
	Vec2f vel;

private:
	sf::Sprite sprite;
};