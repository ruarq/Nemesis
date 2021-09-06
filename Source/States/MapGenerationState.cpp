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
	RoomTileIds rti;
	rti.corner[RoomTileIds::TopLeft] = 0;
	rti.corner[RoomTileIds::TopRight] = 1;
	rti.corner[RoomTileIds::BottomLeft] = 2;
	rti.corner[RoomTileIds::BottomRight] = 3;

	rti.edge[RoomTileIds::Top] = 4;
	rti.edge[RoomTileIds::Left] = 5;
	rti.edge[RoomTileIds::Right] = 6;
	rti.edge[RoomTileIds::Bottom] = 7;

	MapGenInfo mgi;
	mgi.w = 25;
	mgi.h = 25;
	mgi.depth = 1;

	tilemap = GenerateMap(Vec2u(16, 16), mgi, rti);
}

void MapGenerationState::Update()
{
}

void MapGenerationState::Render() const
{
	tilemap.Render(game->window);
}

std::unique_ptr<GameState> MapGenerationState::NextState()
{
	return nullptr; // std::unique_ptr<GameState>(new PlayingState(std::move(tilemap)));
}