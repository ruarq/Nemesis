#pragma once

#include <SFML/System/Clock.hpp>

#include "Types.hpp"

class Time final
{
public:
	/**
	 * @brief update the delta time
	 */
	static void Update();

	/**
	 * @brief get the delta time
	 */
	static f32 Dt();

private:
	static sf::Clock m_clock;
	static f32 m_dt;
};