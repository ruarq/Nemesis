#pragma once

#include <memory>

#include "../GameState.hpp"
#include "../Tilemap.hpp"
#include "../MapGeneration.hpp"

class MapGenerationState final : public GameState
{
public:
	void OnEnter() override;
	void Update() override;
	void Render() const override;

	std::unique_ptr<GameState> NextState() override;

private:
	Tilemap tilemap;
};