#pragma once

#include <memory>

#include <SFML/Graphics.hpp>

#include "Game.hpp"

class GameState
{
public:
	using Ptr = std::unique_ptr<GameState>;

public:
	virtual ~GameState() = default;

public:
	virtual void OnEnter() {}
	virtual void Update() = 0;
	// TODO(ruarq): remove window parameter since it's already accessible through GameState::game->window
	virtual void Render(sf::RenderWindow &window) const = 0;
	virtual void OnExit() {}

	virtual GameState::Ptr NextState() = 0;

public:
	Game *game = nullptr;
};