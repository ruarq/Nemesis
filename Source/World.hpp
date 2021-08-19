#pragma once

#include <vector>

#include "Entity.hpp"

class World final
{
public:
	std::vector<Entity::Ptr> entities;
};