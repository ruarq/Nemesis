#include "MapGeneration.hpp"

BSPTreeRoom::BSPTreeRoom(const u32 x, const u32 y, const u32 w, const u32 h)
	: x(x)
	, y(y)
	, w(w)
	, h(h)
{
}

std::shared_ptr<BSPTreeNode> GenerateBSPTree(const MapGenInfo &mgi)
{
	return Split(0, mgi.depth, 0, 0, mgi.w, mgi.h);
}

std::shared_ptr<BSPTreeNode> Split(const u32 currDepth, const u32 maxDepth, const u32 x, const u32 y, const u32 w, const u32 h)
{
	if (currDepth >= maxDepth)
	{
		auto room = new BSPTreeRoom();
		room->x = x;
		room->y = y;
		room->w = w;
		room->h = h;
		return std::shared_ptr<BSPTreeRoom>(room);
	}

	auto split = new BSPTreeSplit();
	const f32 maxRatio = 0.7f;
	const f32 minRatio = 0.3f;
	const f32 splitRatio = ((std::rand() % 101 * (maxRatio - minRatio)) + 101 * minRatio) / 100.0f;
	if (w > h)
	{
		const u32 wSplit = w * splitRatio;
		split->left = Split(currDepth + 1, maxDepth, x, y, wSplit, h);
		split->right = Split(currDepth + 1, maxDepth, x + wSplit, y, w - wSplit, h);
	}
	else
	{
		const u32 hSplit = h * splitRatio;
		split->left = Split(currDepth + 1, maxDepth, x, y, w, hSplit);
		split->right = Split(currDepth + 1, maxDepth, x, y + hSplit, w, h - hSplit);
	}

	return std::shared_ptr<BSPTreeNode>(split);
}

Tilemap GenerateMap(const Vec2u &tileSize, const MapGenInfo &mgi, const RoomTileIds &rti)
{
	Tilemap tm;
	tm.Create(tileSize, Vec2u(mgi.w, mgi.h));

	auto tree = GenerateBSPTree(mgi);
	PutBSPTree(tm, tree, rti);

	return tm;
}

void PutBSPTree(Tilemap &tm, std::shared_ptr<BSPTreeNode> tree, const RoomTileIds &rti)
{
	if (auto split = std::dynamic_pointer_cast<BSPTreeSplit>(tree))
	{
		PutBSPTree(tm, split->left, rti);
		PutBSPTree(tm, split->right, rti);
	}
	else if (auto room = std::dynamic_pointer_cast<BSPTreeRoom>(tree))
	{
		PutRoom(tm, room, rti);
	}
}

void PutRoom(Tilemap &tm, std::shared_ptr<BSPTreeRoom> room, const RoomTileIds &rti)
{
	for (int x = room->x; x < room->x + room->w - 1; x++)
	{
		tm.SetTile(Vec2u(x, room->y), rti.edge[RoomTileIds::Top]);
		tm.SetTile(Vec2u(x, room->y + room->h - 1), rti.edge[RoomTileIds::Bottom]);
	}

	for (int y = room->y; y < room->y + room->h - 1; y++)
	{
		tm.SetTile(Vec2u(room->x, y), rti.edge[RoomTileIds::Left]);
		tm.SetTile(Vec2u(room->x + room->w - 1, y), rti.edge[RoomTileIds::Right]);
	}
}