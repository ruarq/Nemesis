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
	virtual void OnLeave(GameData &data) {}
	
public:
	bool isFinished = false;
};