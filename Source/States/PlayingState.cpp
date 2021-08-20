#include "PlayingState.hpp"

#include "MenuState.hpp"

void PlayingState::OnEnter(GameData &data)
{
	Audio::PlayMusic("horror", true);
	
	Tileset ts;
	ts.tileSize = Vec2u(8, 8);
	ts.LoadFromFile(Data::Images::Path("Dungeon tileset.png"));

	m_tilemap.LoadFromFile(Data::Maps::Path("Handcrafted.map"));
	m_tilemap.tileset = ts;
	m_tilemap.tileSize = Vec2f(32.0f, 32.0f);
	
	for (u32 y = 0; y < m_tilemap.Size().y; y++)
	{
		for (u32 x = 0; x < m_tilemap.Size().x; x++)
		{
			m_tilemap.SetTile(Vec2u(x, y), std::rand() % m_tilemap.tileset.NumTiles());
		}
	}
}

void PlayingState::Update(GameData &data)
{
}

void PlayingState::Render(GameData &data) const
{
	m_tilemap.Render(data.window);
}

GameState::Ptr PlayingState::NextState(GameData &data)
{
	if (Input::Pressed(sf::Keyboard::Key::Escape))
	{
		return GameState::Ptr(new MenuState());
	}

	return nullptr;
}