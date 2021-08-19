#pragma once

#include <SFML/System/Clock.hpp>

#include "Types.hpp"
#include "Singleton.hpp"

#define gTime Singleton<Time>::get()

class Time final
{
public:
	void update();
	f32 dt();

private:
	sf::Clock m_clock;
	f32 m_dt;
};