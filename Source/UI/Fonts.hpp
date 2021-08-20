#pragma once

#include <iostream>

#include <SFML/Graphics/Font.hpp>

#include "../Data.hpp"

namespace UI
{

/**
 * @brief static class to change the font the ui uses.
 */
class Fonts final
{
public:
	/**
	 * @brief change the global ui font.
	 * @param filename filename of the font
	 * @return true if the font was changed successfully
	 */
	static bool Change(const std::string &filename);

public:
	static sf::Font currentFont;
};

}