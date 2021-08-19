#include "PlayingState.hpp"

#include "MenuState.hpp"

void PlayingState::on_enter(GameData &data)
{
	test_room.load_from_file("Room1.txt");
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
	test_room.render(data.window);
}