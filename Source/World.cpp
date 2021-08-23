#include "World.hpp"

void World::Update()
{
	for (Entity::Ptr &newEntity : newEntities)
	{
		newEntity->Create();
		entities.push_back(std::move(newEntity));
	}
	newEntities.clear();

	for (Entity::Ptr &entity : entities)
	{
		entity->Update(*this);
	}
}

void World::Render(sf::RenderWindow &window) const
{
	for (const Entity::Ptr &entity : entities)
	{
		entity->Render(window);
	}
}

void World::AddEntity(Entity::Ptr entity)
{
	newEntities.push_back(std::move(entity));
}