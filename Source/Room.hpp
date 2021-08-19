#pragma once

#include <iostream>
#include <array>
#include <string>
#include <fstream>

#include <SFML/Graphics.hpp>

#include "Data.hpp"
#include "Tile.hpp"

/**
 * @brief a room is a 9x9 set of tiles.
 */
class Room final
{
public:
	static constexpr i32 width = 9;
	static constexpr i32 height = 9;
	static u32 tile_width;
	static u32 tile_height;
	static sf::Texture ground_texture;
	static sf::Texture wall_texture;

public:
	bool load_from_file(const std::string &filename);
	void set_tile(const Vec2i &pos, const Tile &tile);
	Tile& get_tile(const Vec2i &pos);
	const Tile& get_tile(const Vec2i &pos) const; // not sure if this is required but DUH
	void render(sf::RenderWindow &window) const;

public:
	std::array<Tile, width * height> tiles;
	Vec2i pos;
};