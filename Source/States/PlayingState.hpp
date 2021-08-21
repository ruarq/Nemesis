#pragma once

#include "../GameState.hpp"
#include "../Data.hpp"
#include "../Input.hpp"
#include "../Audio.hpp"
#include "../Tilemap.hpp"
#include "../Tileset.hpp"
#include "../Time.hpp"

class PlayingState final : public GameState
{
public:
	using Ptr = std::unique_ptr<PlayingState>;

public:
	void OnEnter() override;
	void Update() override;
	void Render() const override;

	GameState::Ptr NextState() override;

private:
	Tilemap m_tilemap;
	f32 m_current_tile = 0.0f;
};