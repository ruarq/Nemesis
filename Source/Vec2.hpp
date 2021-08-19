#pragma once

#include <SFML/System/Vector2.hpp>

#include "Types.hpp"

template<typename T>
class Vec2t final
{
public:
	Vec2t()
		: x()
		, y()
	{
	}

	explicit Vec2t(const T x, const T y)
		: x(x)
		, y(y)
	{
	}

	template<typename U>
	Vec2t(const sf::Vector2<U> &other)
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

using Vec2i = Vec2t<i32>;
using Vec2u = Vec2t<u32>;
using Vec2f = Vec2t<f32>;