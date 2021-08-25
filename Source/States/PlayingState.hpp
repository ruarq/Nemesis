#pragma once

#include "../GameState.hpp"
#include "../Data.hpp"
#include "../Input.hpp"
#include "../Audio.hpp"
#include "../Tilemap.hpp"
#include "../Tileset.hpp"
#include "../Time.hpp"
#include "../World.hpp"
#include "../Player.hpp"
#include "../Nemesis.hpp"

class PlayingState final : public GameState
{
public:
	using Ptr = std::unique_ptr<PlayingState>;

public:
	PlayingState(Tilemap &&tilemap);

public:
	void OnEnter() override;
	void Update() override;
	void Render() const override;

	GameState::Ptr NextState() override;

private:
	World world;
};