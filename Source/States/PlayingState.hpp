#pragma once

#include "../GameState.hpp"
#include "../GameData.hpp"
#include "../Room.hpp"
#include "../Data.hpp"
#include "../Input.hpp"

class PlayingState final : public GameState
{
public:
	using Ptr = std::unique_ptr<PlayingState>;

public:
	void on_enter(GameData &data) override;
	void update(GameData &data) override;
	void render(GameData &data) const override;

private:
	Room test_room;
};