#include "PlayingState.hpp"

#include "MenuState.hpp"

void PlayingState::OnEnter()
{
	Audio::PlayMusic("horror", true);
	
	Tileset ts;
	ts.tileSize = Vec2u(8, 8);
	ts.LoadFromFile(Data::Images::Path("Dungeon tileset.png"));

	tilemap.LoadFromFile(Data::Maps::Path("Handcrafted.map"));
	tilemap.tileset = ts;
	tilemap.tileSize = Vec2f(32.0f, 32.0f);
	
	for (u32 y = 0; y < tilemap.Size().y; y++)
	{
		for (u32 x = 0; x < tilemap.Size().x; x++)
		{
			tilemap.SetTile(Vec2u(x, y), std::rand() % tilemap.tileset.NumTiles());
		}
	}
}

void PlayingState::Update()
{
}

void PlayingState::Render() const
{
	tilemap.Render(game->window);
}

GameState::Ptr PlayingState::NextState()
{
	if (Input::Pressed(sf::Keyboard::Key::Escape))
	{
		return GameState::Ptr(new MenuState());
	}

	return nullptr;
}