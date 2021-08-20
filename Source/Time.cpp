#include "Time.hpp"

sf::Clock Time::m_clock;
f32 Time::m_dt;

void Time::Update()
{
	m_dt = m_clock.restart().asSeconds();
}

f32 Time::Dt()
{
	return m_dt;
}