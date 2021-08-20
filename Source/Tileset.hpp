#pragma once

#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>

#include "Vec2.hpp"

using TileId = u32;
extern TileId InvalidTileId;

class Tileset final
{
public:
	/**
	 * @brief load a tileset from a file
	 * @param filename the name of the file
	 * @return wether loading was successful or not
	 */
	bool LoadFromFile(const std::string &filename);

	/**
	 * @brief render a specific tile at the given dest onto the given target
	 * @param target the render target to use
	 * @param dest the destination rect of the tile
	 * @param tileId the id of the tile
	 */
	void Render(sf::RenderTarget &target, const sf::FloatRect &dest, const TileId tileId) const;

	/**
	 * @brief get the total number of tiles (also includes empty space)
	 */
	u32 NumTiles() const;

	/**
	 * @brief get the size of the tileset in tiles
	 */
	Vec2u Size() const;

public:
	/**
	 * @brief the dimension of one tile in the tileset image
	 */
	Vec2u tileSize;

private:
	sf::Texture m_tileset;
	Vec2u m_numTiles;
};