#pragma once

#include <queue>

#include <SFML/Graphics.hpp>

#include "GameState.hpp"

struct GameData final
{
public:
	sf::RenderWindow window;
	std::queue<GameState::Ptr> state_queue;
};