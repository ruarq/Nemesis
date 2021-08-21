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
	virtual void Render() const = 0;
	virtual void OnExit() {}

	virtual GameState::Ptr NextState() = 0;

public:
	Game *game = nullptr;
};