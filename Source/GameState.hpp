#pragma once

#include <memory>

class GameData;

class GameState
{
public:
	using Ptr = std::unique_ptr<GameState>;

public:
	virtual ~GameState() = default;

public:
	virtual void OnEnter(GameData &data) {}
	virtual void Update(GameData &data) = 0;
	virtual void Render(GameData &data) const = 0;
	virtual void OnExit(GameData &data) {}

	virtual GameState::Ptr NextState(GameData &data) = 0;
};