#include "Tilemap.hpp"

void Tilemap::Create(const Vec2u &size)
{
	m_size = size;
	m_tiles.resize(size.x * size.y);
	std::fill(m_tiles.begin(), m_tiles.end(), InvalidTileId);
}


void Tilemap::SetTile(const Vec2u &pos, const TileId tile_id)
{
	m_tiles.at(pos.x + m_size.x * pos.y) = tile_id;
}

void Tilemap::Render(sf::RenderWindow &window) const
{
	for (u32 y = 0; y < m_size.y; y++)
	{
		for (u32 x = 0; x < m_size.x; x++)
		{
			const TileId tile_id = m_tiles.at(x + m_size.x * y);
			if (tile_id != InvalidTileId)
			{
				tileset.Render(window, sf::FloatRect(x * tile_size.x, y * tile_size.y, tile_size.x, tile_size.y), tile_id);
			}
		}
	}
}

Vec2u Tilemap::Size() const
{
	return m_size;
}