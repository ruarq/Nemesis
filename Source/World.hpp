#pragma once

#include <unordered_map>

#include <SFML/Graphics.hpp>

#include "Tilemap.hpp"
#include "Types.hpp"
#include "Entity.hpp"

class World final
{
public:
	void Update();
	void Render(sf::RenderWindow &window) const;
	
	template<typename T>
	void CreateEntity()
	{
		const EntityId uid = GenerateEntityId();
		entities.emplace(uid, std::move(std::unique_ptr<T>(new T(uid))));
	}

	Entity* GetEntityById(const EntityId id) const;
	Entity* GetEntityByName(const std::string &name) const;

private:
	EntityId GenerateEntityId();

public:
	Tilemap tilemap;

private:
	std::unordered_map<EntityId, std::unique_ptr<Entity>> entities;
};