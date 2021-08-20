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
	 * @param fontName font file name, only the filename. the function will search in Data::Fonts::Path() for that file.
	 * @return true if the font was changed successfully
	 */
	static bool Change(const std::string &fontName);

public:
	static sf::Font currentFont;
};

}