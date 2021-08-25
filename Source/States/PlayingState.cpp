#include "PlayingState.hpp"

#include "MenuState.hpp"

PlayingState::PlayingState(Tilemap &&tilemap)
{
	world.tilemap = tilemap;
}

void PlayingState::OnEnter()
{
	Audio::PlayMusic("horror", true);
	
	Tileset ts;
	ts.tileSize = Vec2u(8, 8);
	ts.LoadFromFile(Data::Images::Path("Dungeon tileset.png"));

	world.tilemap.LoadFromFile(Data::Maps::Path("Handcrafted.map"));
	world.tilemap.tileset = ts;
	
	for (u32 y = 0; y < world.tilemap.Size().y; y++)
	{
		for (u32 x = 0; x < world.tilemap.Size().x; x++)
		{
			world.tilemap.SetTile(Vec2u(x, y), std::rand() % world.tilemap.tileset.NumTiles());
		}
	}

	world.CreateEntity<Player>();
	world.CreateEntity<Nemesis>();
}

void PlayingState::Update()
{
	world.Update();
}

void PlayingState::Render() const
{
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