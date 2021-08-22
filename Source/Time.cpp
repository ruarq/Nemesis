#include "Time.hpp"

sf::Clock Time::clock;
f32 Time::dt;

void Time::Update()
{
	dt = clock.restart().asSeconds();
}

f32 Time::Dt()
{
	return dt;
}