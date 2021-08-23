#pragma once

#include <vector>

#include "Entity.hpp"

class World final
{
public:
	void Update();
	void Render(sf::RenderWindow &window) const;

	void AddEntity(Entity::Ptr entity);

private:
	
	std::vector<Entity::Ptr> newEntities;
	std::vector<Entity::Ptr> entities;
};