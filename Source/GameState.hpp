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
	virtual void on_enter(GameData &data) {}
	virtual void update(GameData &data) = 0;
	virtual void render(GameData &data) const = 0;
	virtual void on_leave(GameData &data) {}
	
public:
	bool is_finished = false;
};