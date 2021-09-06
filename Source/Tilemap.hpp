#pragma once

#include <string>
#include <fstream>

#include <SFML/Graphics.hpp>

#include "Types.hpp"
#include "Tileset.hpp"
#include "Vec2.hpp"

class Tilemap final
{
public:
	Tilemap() = default;
	Tilemap(const Tilemap &other);

public:
	/**
	 * @brief create a tilemap
	 * @param tileSize the size of one tile
	 * @param size the size of the tilemap (in tiles, not pixels)
	 */
	void Create(const Vec2f &tileSize, const Vec2u &size);

	/**
	 * @brief set the tiledId of a tile in the tilemap
	 * @param pos the position of the tile
	 * @param tileId the id of the tile
	 */
	void SetTile(const Vec2u &pos, const TileId tileId);

	/**
	 * @brief render the tilemap
	 * @param window the window to render the tilemap onto
	 */
	void Render(sf::RenderWindow &window) const;

	/**
	 * @brief get the size of the tilemap in *tiles*
	 */
	Vec2u Size() const;

	/**
	 * @brief get the size of the tilemap in *pixels*
	 */
	Vec2f RealSize() const;

	/**
	 * @brief load a tilemap from a file
	 * @param filename the file to load the tilemap from
	 */
	bool LoadFromFile(const std::string &filename);

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
	std::vector<TileId> tiles;
	Vec2u size;
};