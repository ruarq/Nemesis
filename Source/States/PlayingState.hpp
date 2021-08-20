#pragma once

#include "../GameState.hpp"
#include "../GameData.hpp"
#include "../Data.hpp"
#include "../Input.hpp"
#include "../AudioSystem.hpp"
#include "../Tilemap.hpp"
#include "../Time.hpp"

class PlayingState final : public GameState
{
public:
	using Ptr = std::unique_ptr<PlayingState>;

public:
	void on_enter(GameData &data) override;
	void update(GameData &data) override;
	void render(GameData &data) const override;

private:
	Tilemap m_tilemap;
	f32 m_current_tile = 0.0f;
};