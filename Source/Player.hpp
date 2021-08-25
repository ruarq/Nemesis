#pragma once

#include <SFML/Graphics.hpp>

#include "TextureManager.hpp"
#include "Entity.hpp"
#include "Data.hpp"
#include "Utility.hpp"
#include "Input.hpp"
#include "Time.hpp"
#include "World.hpp"

class Player final : public Entity
{
public:
	static constexpr f32 speed = 250.0f;

public:
	Player(const EntityId id);

public:
	void Update(World &world) override;
	void Render(sf::RenderWindow &window) const override;

private:
	void HandleMovement();

private:
	sf::Sprite sprite;
};