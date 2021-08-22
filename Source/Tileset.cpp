#include "Tileset.hpp"

bool ValidateTileSize(const Vec2u &tilemapSize, const Vec2u &tileSize)
{
	/**
	 * the tilemapSize should be a multiple of tileSize,
	 * so that an exact amount of tiles fit along an axis (not like 25.76 tiles along the x or y axis).
	 * this functions just makes sure that the tilemapSize is a multiple of tileSize.
	 */
	if (tilemapSize.x == 0 || tilemapSize.y == 0 ||
		tileSize.x == 0 || tileSize.y == 0)
	{
		return false;
	}

	return tilemapSize.x % tileSize.x == 0 && tilemapSize.y % tileSize.y == 0;
}

bool Tileset::LoadFromFile(const std::string &filename)
{
	tileset = TextureManager::LoadTexture(filename);

	if (!tileset)
	{
		return false;
	}

	if (!ValidateTileSize(tileset->getSize(), tileSize))
	{
		std::cout << "[Tileset] => Couldn't validate tile size of \"" << filename << "\"\n";
		return false;
	}

	numTiles.x = tileset->getSize().x / tileSize.x;
	numTiles.y = tileset->getSize().y / tileSize.y;
	
	return true;
}

void Tileset::Render(sf::RenderTarget &target, const sf::FloatRect &dest, const TileId tileId) const
{
	const Vec2u tilePos((tileId % numTiles.x) * tileSize.x, (tileId / numTiles.x) * tileSize.y);
	const sf::IntRect tileRect(tilePos.x, tilePos.y, tileSize.x, tileSize.y);

	sf::Sprite sprite;
	sprite.setTexture(*tileset);
	sprite.setTextureRect(tileRect);
	sprite.setPosition(dest.left, dest.top);
	sprite.setScale(dest.width / f32(tileSize.x), dest.height / f32(tileSize.y));
	target.draw(sprite);
}

u32 Tileset::NumTiles() const
{
	return numTiles.x * numTiles.y;
}

Vec2u Tileset::Size() const
{
	return numTiles;
}