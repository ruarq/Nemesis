#include "Game.hpp"
#include "States/MenuState.hpp"

int main()
{
	Game game;
	game.data.state_queue.push(MenuState::Ptr(new MenuState()));
	game.run();	

	return 0;
}