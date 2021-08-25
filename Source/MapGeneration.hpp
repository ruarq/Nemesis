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

std::shared_ptr<BSPTreeNode> GenerateBSPTree(const u32 w, const u32 h, const u32 depth);
std::shared_ptr<BSPTreeNode> Split(const u32 currDepth, const u32 maxDepth, const u32 x, const u32 y, const u32 w, const u32 h);
Tilemap GenerateMap(std::shared_ptr<BSPTreeNode> tree);