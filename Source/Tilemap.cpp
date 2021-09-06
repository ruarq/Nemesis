#include "Tilemap.hpp"


Tilemap::Tilemap(const Tilemap &other)
{
	this->Create(other.size, other.Size());
	offset = other.offset;
	tileset = other.tileset;
	tiles = other.tiles;
}

void Tilemap::Create(const Vec2f &tileSize, const Vec2u &size)
{
	this->tileSize = tileSize;
	this->size = size;
	tiles.resize(size.x * size.y);
	std::fill(tiles.begin(), tiles.end(), INVALID_TILE_ID);
}

void Tilemap::SetTile(const Vec2u &pos, const TileId tile_id)
{
	tiles.at(pos.x + size.x * pos.y) = tile_id;
}

void Tilemap::Render(sf::RenderWindow &window) const
{
	/**
	 * render every tile in the tilemap
	 */
	for (u32 y = 0; y < size.y; y++)
	{
		for (u32 x = 0; x < size.x; x++)
		{
			const TileId tileId = tiles.at(x + size.x * y);
			if (tileId != INVALID_TILE_ID)
			{
				tileset.Render(window, sf::FloatRect(x * tileSize.x + offset.x, y * tileSize.y + offset.y, tileSize.x, tileSize.y), tileId);
			}
		}
	}
}

Vec2u Tilemap::Size() const
{
	return size;
}

bool Tilemap::LoadFromFile(const std::string &filename)
{
	std::ifstream file(filename);
	
	if (!file.is_open())
	{
		std::cout << "[Tilemap] => Couldn't load \"" << filename << "\"\n";
		return false;
	}
	
	file >> size;
	file >> tileSize;
	this->Create(tileSize, size);

	for (u32 y = 0; y < size.y; y++)
	{
		for (u32 x = 0; x < size.x; x++)
		{
			TileId tileId;
			file >> tileId;
			tiles.at(y * size.x + x) = tileId;
		}
	}

	return true;
}