#include "Fonts.hpp"

namespace UI
{

sf::Font Fonts::currentFont;

bool Fonts::Change(const std::string &filename)
{
	sf::Font newFont;

	if (!newFont.loadFromFile(filename))
	{
		std::cout << "[UI::Fonts] => Couldn't load font \"" << filename << "\"\n";
		return false;
	}

	currentFont = newFont;
	return true;
}

}