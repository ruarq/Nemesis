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

	if (!ValidateTileSize(m_tileset.getSize(), tile_size))
	{
		std::cout << "[Tileset] => Couldn't validate tile size of \"" << filename << "\"\n";
		return false;
	}

	m_num_tiles.x = m_tileset.getSize().x / tile_size.x;
	m_num_tiles.y = m_tileset.getSize().y / tile_size.y;
	
	return true;
}

void Tileset::Render(sf::RenderTarget &target, const sf::FloatRect &dest, const TileId tileid) const
{
	const Vec2u tile_pos((tileid % m_num_tiles.x) * tile_size.x, (tileid / m_num_tiles.x) * tile_size.y);
	const sf::IntRect tile_rect(tile_pos.x, tile_pos.y, tile_size.x, tile_size.y);

	sf::Sprite sprite;
	sprite.setTexture(m_tileset);
	sprite.setTextureRect(tile_rect);
	sprite.setPosition(dest.left, dest.top);
	sprite.setScale(dest.width / f32(tile_size.x), dest.height / f32(tile_size.y));
	target.draw(sprite);
}

u32 Tileset::NumTiles() const
{
	return m_num_tiles.x * m_num_tiles.y;
}