#pragma once

#include "Vec2.hpp"

class Tile final
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
	bool has_key = false; // wether there is a key on the tile or not
};