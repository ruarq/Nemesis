#include "MapGeneration.hpp"

BSPTreeRoom::BSPTreeRoom(const u32 x, const u32 y, const u32 w, const u32 h)
	: x(x)
	, y(y)
	, w(w)
	, h(h)
{
}

std::shared_ptr<BSPTreeNode> GenerateBSPTree(const u32 w, const u32 h, const u32 depth)
{
	return Split(0, depth, 0, 0, w, h);
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

Tilemap GenerateMap(std::shared_ptr<BSPTreeNode> tree)
{
	
}