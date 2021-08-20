#include "PlayingState.hpp"

#include "MenuState.hpp"

void PlayingState::on_enter(GameData &data)
{
	gAudioSystem->play_music("horror", true);
	
	Tileset ts;
	ts.tile_size.x = 8;
	ts.tile_size.y = 8;
	ts.LoadFromFile(Data::Images::path("TestTileset.png"));

	m_tilemap.Create(Vec2u(32, 32));
	m_tilemap.tileset = ts;
	m_tilemap.tile_size.x = 32.0f;
	m_tilemap.tile_size.y = 32.0f;
	
	for (u32 y = 0; y < m_tilemap.Size().y; y++)
	{
		for (u32 x = 0; x < m_tilemap.Size().x; x++)
		{
			m_tilemap.SetTile(Vec2u(x, y), std::rand() % m_tilemap.tileset.NumTiles());
		}
	}
}

void PlayingState::update(GameData &data)
{
	if (gInput->pressed(sf::Keyboard::Key::Escape))
	{
		data.state_queue.push(MenuState::Ptr(new MenuState()));
		is_finished = true;
	}
}

void PlayingState::render(GameData &data) const
{
	m_tilemap.Render(data.window);
}