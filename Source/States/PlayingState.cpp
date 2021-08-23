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
	
	for (u32 y = 0; y < tilemap.Size().y; y++)
	{
		for (u32 x = 0; x < tilemap.Size().x; x++)
		{
			tilemap.SetTile(Vec2u(x, y), std::rand() % tilemap.tileset.NumTiles());
		}
	}

	world.AddEntity(Entity::Ptr(new Player()));
}

void PlayingState::Update()
{
	world.Update();
}

void PlayingState::Render() const
{
	tilemap.Render(game->window);
	world.Render(game->window);
}

GameState::Ptr PlayingState::NextState()
{
	if (Input::Pressed(sf::Keyboard::Key::Escape))
	{
		return GameState::Ptr(new MenuState());
	}

	return nullptr;
}