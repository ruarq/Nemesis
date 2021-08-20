#include "Fonts.hpp"

namespace UI
{

sf::Font Fonts::currentFont;

bool Fonts::Change(const std::string &fontName)
{
	sf::Font newFont;

	if (!newFont.loadFromFile(Data::Fonts::Path(fontName)))
	{
		std::cout << "[UI::Fonts] => Couldn't load font \"" << fontName << "\"\n";
		return false;
	}

	currentFont = newFont;
	return true;
}

}