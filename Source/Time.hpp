#pragma once

#include <SFML/System/Clock.hpp>

#include "Types.hpp"

class Time final
{
public:
	static void Update();
	static f32 Dt();

private:
	static sf::Clock m_clock;
	static f32 m_dt;
};