#include "Game.hpp"
#include "States/MenuState.hpp"

int main()
{
	Game game;
	game.data.states.push(MenuState::Ptr(new MenuState()));
	game.Run();	

	return 0;
}