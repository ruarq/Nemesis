#include "Utility.hpp"

void SetSpriteSize(sf::Sprite &sprite, const Vec2f &size)
{
	const sf::Texture *texture = sprite.getTexture();
	sprite.setScale(size.x / texture->getSize().x, size.x / texture->getSize().y);
}

Vec2f GetSpriteSize(const sf::Sprite &sprite)
{
	return GetDefaultSpriteSize(sprite) * Vec2f(sprite.getScale());
}

Vec2f GetDefaultSpriteSize(const sf::Sprite &sprite)
{
	return sprite.getTexture()->getSize();
}