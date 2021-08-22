#pragma once

#include <vector>

#include "Entity.hpp"

class World final
{
public:
	void Update();



private:
	std::vector<Entity::Ptr> entities;
};