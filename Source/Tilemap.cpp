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
	/**
	 * render every tile in the tilemap
	 */
	for (u32 y = 0; y < m_size.y; y++)
	{
		for (u32 x = 0; x < m_size.x; x++)
		{
			const TileId tileId = m_tiles.at(x + m_size.x * y);
			if (tileId != InvalidTileId)
			{
				tileset.Render(window, sf::FloatRect(x * tileSize.x, y * tileSize.y, tileSize.x, tileSize.y), tileId);
			}
		}
	}
}

Vec2u Tilemap::Size() const
{
	return m_size;
}