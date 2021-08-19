#pragma once

#include "Vec2.hpp"

class Tile
{
public:
	enum Type
	{
		Empty,
		Ground,
		Wall
	};

public:
	Tile() = default;
	explicit Tile(const Type type);

public:
	Type type = Empty;
};