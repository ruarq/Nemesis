/**
 * https://eskerda.com/bsp-dungeon-generation/
 * "BSP-Tree"
 */

#pragma once

#include <memory>
#include <cstdlib>

#include "Types.hpp"
#include "Tilemap.hpp"

struct BSPTreeNode
{
	virtual ~BSPTreeNode() = default;
};

struct BSPTreeSplit final : public BSPTreeNode
{
	std::shared_ptr<BSPTreeNode> left, right;
};

struct BSPTreeRoom final : public BSPTreeNode
{
	BSPTreeRoom() = default;
	BSPTreeRoom(const u32 x, const u32 y, const u32 w, const u32 h);

	u32 x, y, w, h;
};

struct MapGenInfo final
{
	u32 w, h, depth;
};

class RoomTileIds final
{
public:
	enum Corner
	{
		TopLeft,
		TopRight,
		BottomLeft,
		BottomRight
	};

	enum Edge
	{
		Top,
		Left,
		Right,
		Bottom
	};

public:
	TileId corner[4];
	TileId edge[4];
};

std::shared_ptr<BSPTreeNode> GenerateBSPTree(const MapGenInfo &mgi);
std::shared_ptr<BSPTreeNode> Split(const u32 currDepth, const u32 maxDepth, const u32 x, const u32 y, const u32 w, const u32 h);
Tilemap GenerateMap(const Vec2u &tileSize, const MapGenInfo &mgi, const RoomTileIds &rti);
void PutBSPTree(Tilemap &tm, std::shared_ptr<BSPTreeNode> tree, const RoomTileIds &rti);
void PutRoom(Tilemap &tm, std::shared_ptr<BSPTreeRoom> room, const RoomTileIds &rti);