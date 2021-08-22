#include "TextureManager.hpp"

std::unordered_map<std::string, sf::Texture> TextureManager::textures;

sf::Texture* TextureManager::LoadTexture(const std::string &filename)
{
	sf::Texture texture;

	if (!texture.loadFromFile(filename))
	{
		return nullptr;
	}

	const auto &[itr, emplace_success] = textures.emplace(filename, texture);

	if (!emplace_success)
	{
		return nullptr;
	}
	else
	{
		return &(itr->second);
	}
}
