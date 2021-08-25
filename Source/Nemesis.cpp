#include "Nemesis.hpp"

Nemesis::Nemesis(const EntityId id)
	: Entity(id)
{
	name = "nemesis";

	sprite.setTexture(*TextureManager::LoadTexture(Data::Images::Path("Nemesis.jpg")));
	SetSpriteSize(sprite, Vec2f(16.0f, 16.0f));
	sprite.setOrigin(GetDefaultSpriteSize(sprite) / 2.0f);
}

void Nemesis::Update(World &world)
{
	Vec2f acc, turnAcc;

	if (player)
	{
		acc = (player->pos - pos).Norm() * accForce;
	}
	else
	{
		player = world.GetEntityByName("player");
	}

	// update vel based on acc
	vel += acc * Time::Dt();

	// apply a turn force
	turnAcc = (acc - vel).Norm() * turnForce;
	vel += turnAcc * Time::Dt();

	// make sure vel is never bigger than maxSpeed
	if (vel.Length() > maxSpeed)
	{
		vel = vel.Norm() * maxSpeed;
	}

	// update pos and sprite
	pos += vel * Time::Dt();

	sprite.setPosition(pos);
}

void Nemesis::Render(sf::RenderWindow &window) const
{
	window.draw(sprite);
}