#include "TextBox.hpp"

namespace UI
{

void TextBox::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	m_sfText.setFont(Fonts::currentFont);
	m_sfText.setCharacterSize(int(fontSize));

	if (wrappedText)
	{
		m_sfText.setString(this->WrapText());
	}
	else
	{
		m_sfText.setString(text);
	}

	switch (textAlign)
	{
		case TextAlign::Left:
			m_sfText.setPosition(box.left, box.top);
			break;

		case TextAlign::Centered:
			m_sfText.setPosition(box.left + box.width / 2.0f - m_sfText.getLocalBounds().width / 2.0f, box.top);
			break;

		case TextAlign::Right:
			m_sfText.setPosition(box.left + box.width - m_sfText.getLocalBounds().width, box.top);
			break;
	}

	// draw the text and the box
	target.draw(m_sfText);
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
	m_sfText.setString(this->WrapText());
	box.height = m_sfText.getLocalBounds().height;
}

std::string TextBox::WrapText() const
{
	// update the local bounds, so we can use them in the calculation below.
	m_sfText.setString(text);

	// calculate where to insert newlines
	std::string wrappedString = text;
	const f32 boxToBoundsRatio = box.width / m_sfText.getLocalBounds().width;
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