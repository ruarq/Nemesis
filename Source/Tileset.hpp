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
	bool LoadFromFile(const std::string &filename);
	void Render(sf::RenderTarget &target, const sf::FloatRect &dest, const TileId tileId) const;
	u32 NumTiles() const;

public:
	Vec2u tileSize;

private:
	sf::Texture m_tileset;
	Vec2u m_numTiles;
};