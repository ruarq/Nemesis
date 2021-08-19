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
	 * @param font_name font file name, only the filename. the function will search in Data::Fonts::path() for that file.
	 * @return true if the font was changed successfully
	 */
	static bool change(const std::string &font_name);

public:
	static sf::Font current_font;
};

}