#include "World.hpp"

#include "Entity.hpp"

void World::Update()
{
	for (auto &[id, entity] : entities)
	{
		entity->Update(*this);
	}
}

void World::Render(sf::RenderWindow &window) const
{
	tilemap.Render(window);

	for (auto &[id, entity] : entities)
	{
		entity->Render(window);
	}
}

Entity* World::GetEntityById(const EntityId id) const
{
	auto itr = entities.find(id);
	if (itr != entities.end())
	{
		return itr->second.get();
	}
	else
	{
		return nullptr;
	}
}

Entity* World::GetEntityByName(const std::string &name) const
{
	for (auto &[id, entity] : entities)
	{
		if (entity->name == name)
		{
			return entity.get();
		}
	}

	return nullptr;
}

EntityId World::GenerateEntityId()
{
	static EntityId id = 0;
	return id++;
}