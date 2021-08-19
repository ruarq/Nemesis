#include "Time.hpp"

void Time::update()
{
	m_dt = m_clock.restart().asSeconds();
}

f32 Time::dt()
{
	return m_dt;
}