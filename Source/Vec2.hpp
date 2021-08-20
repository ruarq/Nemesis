#pragma once

#include <SFML/System/Vector2.hpp>

#include "Types.hpp"

template<typename T>
class Vec2 final
{
public:
	Vec2()
		: x()
		, y()
	{
	}

	explicit Vec2(const T x, const T y)
		: x(x)
		, y(y)
	{
	}

	template<typename U>
	Vec2(const sf::Vector2<U> &other)
		: x(other.x)
		, y(other.y)
	{
	}

public:
	operator sf::Vector2<T>() const
	{
		return sf::Vector2<T>(x, y);
	}

	template<typename U>
	operator Vec2t<U>() const
	{
		return Vec2t<U>(x, y);
	}

public:
	T x, y;
};

using Vec2i = Vec2<i32>;
using Vec2u = Vec2<u32>;
using Vec2f = Vec2<f32>;