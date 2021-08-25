#include "MapGenerationState.hpp"

#include "PlayingState.hpp"

void DrawTree(sf::RenderWindow &window, const std::shared_ptr<BSPTreeNode> &node)
{
	if (auto room = std::dynamic_pointer_cast<BSPTreeRoom>(node))
	{
		sf::RectangleShape rs;
		rs.setFillColor(sf::Color::Transparent);
		rs.setOutlineThickness(1.0f);
		rs.setPosition(room->x, room->y);
		rs.setSize(Vec2f(room->w, room->h));
		window.draw(rs);
	}
	else if (auto split = std::dynamic_pointer_cast<BSPTreeSplit>(node))
	{
		DrawTree(window, split->left);
		DrawTree(window, split->right);
	}
}

void MapGenerationState::OnEnter()
{
	tree = GenerateBSPTree(game->window.getSize().x, game->window.getSize().y, 5);
}

void MapGenerationState::Update()
{
}

void MapGenerationState::Render() const
{
	DrawTree(game->window, tree);
}

std::unique_ptr<GameState> MapGenerationState::NextState()
{
	return nullptr; // std::unique_ptr<GameState>(new PlayingState(std::move(tilemap)));
}