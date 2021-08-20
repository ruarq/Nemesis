#include "Tileset.hpp"

TileId InvalidTileId = std::numeric_limits<TileId>::max();

bool ValidateTileSize(const Vec2u &tilemap_size, const Vec2u &tile_size)
{
	if (tilemap_size.x == 0 || tilemap_size.y == 0 ||
		tile_size.x == 0 || tile_size.y == 0)
	{
		return false;
	}

	return tilemap_size.x % tile_size.x == 0 && tilemap_size.y % tile_size.y == 0;
}

bool Tileset::LoadFromFile(const std::string &filename)
{
	if (!m_tileset.loadFromFile(filename))
	{
		std::cout << "[Tileset] => Couldn't load tileset \"" << filename << "\"\n";
		return false;
	}

	if (!ValidateTileSize(m_tileset.getSize(), tileSize))
	{
		std::cout << "[Tileset] => Couldn't validate tile size of \"" << filename << "\"\n";
		return false;
	}

	m_numTiles.x = m_tileset.getSize().x / tileSize.x;
	m_numTiles.y = m_tileset.getSize().y / tileSize.y;
	
	return true;
}

void Tileset::Render(sf::RenderTarget &target, const sf::FloatRect &dest, const TileId tileId) const
{
	const Vec2u tilePos((tileId % m_numTiles.x) * tileSize.x, (tileId / m_numTiles.x) * tileSize.y);
	const sf::IntRect tileRect(tilePos.x, tilePos.y, tileSize.x, tileSize.y);

	sf::Sprite sprite;
	sprite.setTexture(m_tileset);
	sprite.setTextureRect(tileRect);
	sprite.setPosition(dest.left, dest.top);
	sprite.setScale(dest.width / f32(tileSize.x), dest.height / f32(tileSize.y));
	target.draw(sprite);
}

u32 Tileset::NumTiles() const
{
	return m_numTiles.x * m_numTiles.y;
}