#pragma once

#include <iostream>

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
	Vec2<T>& operator+=(const Vec2<T> &other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}

	operator sf::Vector2<T>() const
	{
		return sf::Vector2<T>(x, y);
	}

	template<typename U>
	operator Vec2<U>() const
	{
		return Vec2<U>(x, y);
	}

public:
	T x, y;
};

template<typename T>
inline bool operator==(const Vec2<T> &a, const Vec2<T> &b)
{
	return a.x == b.x && a.y == b.y;
}

template<typename T>
inline bool operator!=(const Vec2<T> &a, const Vec2<T> &b)
{
	return !(a == b);
}

template<typename T, typename U>
inline Vec2<T> operator*(const Vec2<T> &v, const U t)
{
	return Vec2<T>(v.x * t, v.y * t);
}

using Vec2i = Vec2<i32>;
using Vec2u = Vec2<u32>;
using Vec2f = Vec2<f32>;

/**
 * utility functions
 */
template<typename T>
std::ostream& operator<<(std::ostream& os, const Vec2<T> &vec2)
{
	os << vec2.x << " " << vec2.y;
	return os;
}

template<typename T>
std::istream& operator>>(std::istream& is, Vec2<T> &vec2)
{
	is >> vec2.x >> vec2.y;
	return is;
}