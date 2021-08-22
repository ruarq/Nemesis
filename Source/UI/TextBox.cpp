#include "TextBox.hpp"

namespace UI
{

void TextBox::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	sfText.setFont(Fonts::currentFont);
	sfText.setCharacterSize(int(fontSize));

	if (wrappedText)
	{
		sfText.setString(this->WrapText());
	}
	else
	{
		sfText.setString(text);
	}

	switch (textAlign)
	{
		case TextAlign::Left:
			sfText.setPosition(box.left, box.top);
			break;

		case TextAlign::Centered:
			sfText.setPosition(box.left + box.width / 2.0f - sfText.getLocalBounds().width / 2.0f, box.top);
			break;

		case TextAlign::Right:
			sfText.setPosition(box.left + box.width - sfText.getLocalBounds().width, box.top);
			break;
	}

	// draw the text and the box
	target.draw(sfText);
	if (drawBox)
	{
		sf::RectangleShape shape;
		shape.setFillColor(sf::Color::Transparent);
		shape.setOutlineThickness(1.0f);
		shape.setPosition(box.left, box.top);
		shape.setSize(Vec2f(box.width, box.height));
		target.draw(shape);
	}
}

void TextBox::AdjustBoxHeight()
{
	sfText.setString(this->WrapText());
	box.height = sfText.getLocalBounds().height;
}

std::string TextBox::WrapText() const
{
	// update the local bounds, so we can use them in the calculation below.
	sfText.setString(text);

	// calculate where to insert newlines
	std::string wrappedString = text;
	const f32 boxToBoundsRatio = box.width / sfText.getLocalBounds().width;
	const u32 insertNewlineStep = boxToBoundsRatio * text.size();

	if (insertNewlineStep == 0)
	{
		return text;
	}

	for (
		u32 insertIndex = insertNewlineStep;
		insertIndex < wrappedString.size();
		insertIndex += insertNewlineStep + 1)
	{
		// if there is a space or tab at the current insert location, replace it with a newline
		if (wrappedString[insertIndex] == ' ' || wrappedString[insertIndex] == '\t')
		{
			wrappedString[insertIndex] = '\n';
		}
		// only insert a newline if there isn't already one
		else if (wrappedString[insertIndex] != '\n')
		{
			wrappedString.insert(wrappedString.begin() + insertIndex, 1, '\n');
		}
	}

	return wrappedString;
}

}