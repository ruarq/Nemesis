#pragma once

#include <SFML/Graphics.hpp>

#include "Entity.hpp"
#include "World.hpp"
#include "Utility.hpp"
#include "TextureManager.hpp"
#include "Data.hpp"
#include "Time.hpp"

class Nemesis final : public Entity
{
public:
	static constexpr f32 accForce = 350.0f;
	static constexpr f32 turnForce = 500.0f;
	static constexpr f32 maxSpeed = 260.0f;

public:
	explicit Nemesis(const EntityId id);

public:
	void Update(World &world) override;
	void Render(sf::RenderWindow &window) const override;

public:
	Vec2f vel;

private:
	sf::Sprite sprite;
	Entity *player = nullptr;
};