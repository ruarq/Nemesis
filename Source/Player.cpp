#include "Player.hpp"

void Player::Create()
{
	sprite.setTexture(*TextureManager::LoadTexture(Data::Images::Path("Key.png")));
	SetSpriteSize(sprite, Vec2f(32.0f, 32.0f));
	sprite.setOrigin(GetDefaultSpriteSize(sprite) / 2.0f);
}

void Player::Update(World &world)
{
	vel = Vec2f();

	if (Input::Down(sf::Keyboard::Key::W))
	{
		vel.y -= speed;
	}

	if (Input::Down(sf::Keyboard::Key::A))
	{
		vel.x -= speed;
	}

	if (Input::Down(sf::Keyboard::Key::S))
	{
		vel.y += speed;
	}

	if (Input::Down(sf::Keyboard::Key::D))
	{
		vel.x += speed;
	}

	pos += vel * Time::Dt();
}

void Player::Render(sf::RenderWindow &window)
{
	sprite.setPosition(pos);
	window.draw(sprite);
}