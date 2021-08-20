#include "PlayingState.hpp"

#include "MenuState.hpp"

void PlayingState::OnEnter(GameData &data)
{
	AudioSystem::PlayMusic("horror", true);
	
	Tileset ts;
	ts.tileSize = Vec2u(8, 8);
	ts.LoadFromFile(Data::Images::Path("TestTileset.png"));

	m_tilemap.Create(Vec2u(32, 32));
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
	if (Input::Pressed(sf::Keyboard::Key::Escape))
	{
		data.states.push(MenuState::Ptr(new MenuState()));
		isFinished = true;
	}
}

void PlayingState::Render(GameData &data) const
{
	m_tilemap.Render(data.window);
}