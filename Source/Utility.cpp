#include "Utility.hpp"

void SetSpriteSize(sf::Sprite &sprite, const Vec2f &size)
{
	const sf::Texture *texture = sprite.getTexture();
	sprite.setScale(size.x / texture->getSize().x, size.x / texture->getSize().y);
}