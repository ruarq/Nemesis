#include "Entity.hpp"

Entity::Entity(const EntityId id)
	: id(id)
	, name(std::to_string(id))
{
}