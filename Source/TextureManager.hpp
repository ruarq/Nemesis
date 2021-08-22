#pragma once

#include <string>
#include <unordered_map>

#include <SFML/Graphics.hpp>

#include "Types.hpp"

class TextureManager final
{
public:
	static sf::Texture* LoadTexture(const std::string &filename);

private:
	static std::unordered_map<std::string, sf::Texture> m_textures;
};