#pragma once

#include <string>
#include <memory>

#include <SFML/Graphics.hpp>

#include "../Vec2.hpp"
#include "../Types.hpp"
#include "Fonts.hpp"
#include "TextAlign.hpp"

namespace UI
{

class TextBox : public sf::Drawable
{
public:
	void draw(sf::RenderTarget &target, sf::RenderStates states) const final override;
	void AdjustBoxHeight();

public:
	/**
	 * @brief the rect the text will be rendered in.
	 */
	sf::FloatRect box;

	/**
	 * @brief the text the text box will render.
	 */
	std::string text;

	/**
	 * @brief wether to draw the box rect or not.
	 */
	bool drawBox = false;

	/**
	 * @brief how the text should be aligned horizontally.
	 */
	TextAlign textAlign;

	/**
	 * @brief if the text should be force to be in the box rect.
	 */
	bool wrappedText = true;

	/**
	 * @brief font size
	 */
	float fontSize = 30.0f;

private:
	/**
	 * @brief this is responsible to make the TextBox::text fit into the TextBox::box when it's rendered.
	 */
	std::string WrapText() const;

private:
	mutable sf::Text sfText;
};

}