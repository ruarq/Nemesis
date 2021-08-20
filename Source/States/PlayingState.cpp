#include "PlayingState.hpp"

#include "MenuState.hpp"

void PlayingState::OnEnter(GameData &data)
{
	Audio::PlayMusic("horror", true);
	
	Tileset ts;
	ts.tileSize = Vec2u(8, 8);
	ts.LoadFromFile(Data::Images::Path("Dungeon tileset.png"));

	m_tilemap.LoadFromFile(Data::Maps::Path("Test.map"));
	m_tilemap.tileset = ts;
	m_tilemap.tileSize = Vec2f(32.0f, 32.0f);
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