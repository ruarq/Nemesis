#include "Player.hpp"

void Player::Create()
{
	sprite.setTexture(*TextureManager::LoadTexture(Data::Images::Path("Key.png")));
	SetSpriteSize(sprite, Vec2f(32.0f, 32.0f));
}

void Player::Update(World &world)
{
	pos += vel * Time::Dt();
}

void Player::Render(sf::RenderWindow &window)
{
	sprite.setPosition(pos);
	window.draw(sprite);
}