#pragma once

#include <queue>

#include <SFML/Graphics.hpp>

#include "GameState.hpp"

struct GameData final
{
public:
	sf::RenderWindow window;
	sf::View camera;
	bool isRunning = false;
};