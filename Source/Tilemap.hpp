#pragma once

#include "Types.hpp"
#include "Tileset.hpp"
#include "Vec2.hpp"

class Tilemap final
{
public:
	void Create(const Vec2u &size);
	void SetTile(const Vec2u &pos, const TileId tileId);
	void Render(sf::RenderWindow &window) const;
	Vec2u Size() const;

public:
	/**
	 * @brief how big each tile should be
	 */
	Vec2f tileSize;

	/**
	 * @brief essentially the top-left position of where the tilemap should be drawn.
	 */
	Vec2f offset;

	/**
	 * @brief tileset to use
	 */
	Tileset tileset;

private:
	std::vector<TileId> m_tiles;
	Vec2u m_size;
};