#include "Fonts.hpp"

namespace UI
{

sf::Font Fonts::current_font;

bool Fonts::change(const std::string &font_name)
{
	sf::Font new_font;

	if (!new_font.loadFromFile(Data::Fonts::path(font_name)))
	{
		std::cout << "[UI::Fonts] => Couldn't load font \"" << font_name << "\"\n";
		return false;
	}

	current_font = new_font;
	return true;
}

}