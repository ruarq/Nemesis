#include "Player.hpp"

Player::Player(const EntityId id)
	: Entity(id)
{
	name = "player";

	sprite.setTexture(*TextureManager::LoadTexture(Data::Images::Path("megaman.png")));
	SetSpriteSize(sprite, Vec2f(16.0f, 16.0f));
	sprite.setOrigin(GetDefaultSpriteSize(sprite) / 2.0f);
}

void Player::Update(World &world)
{
	this->HandleMovement();

	sprite.setPosition(pos);
}

void Player::Render(sf::RenderWindow &window) const
{
	window.draw(sprite);
}

void Player::HandleMovement()
{
	Vec2f vel;

	if (Input::Down(sf::Keyboard::W))
	{
		vel.y -= speed;
	}

	if (Input::Down(sf::Keyboard::S))
	{
		vel.y += speed;
	}

	if (Input::Down(sf::Keyboard::A))
	{
		vel.x -= speed;
	}

	if (Input::Down(sf::Keyboard::D))
	{
		vel.x += speed;
	}

	if (vel.Length() > speed)
	{
		vel = vel.Norm() * speed;
	}

	pos += vel * Time::Dt();
}