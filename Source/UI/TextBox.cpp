#include "TextBox.hpp"

namespace UI
{

void TextBox::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	m_sf_text.setFont(Fonts::current_font);
	m_sf_text.setCharacterSize(int(font_size));

	if (wrapped_text)
	{
		m_sf_text.setString(this->wrap_text());
	}
	else
	{
		m_sf_text.setString(text);
	}

	switch (text_align)
	{
		case TextAlign::left:
			m_sf_text.setPosition(box.left, box.top);
			break;

		case TextAlign::centered:
			m_sf_text.setPosition(box.left + box.width / 2.0f - m_sf_text.getLocalBounds().width / 2.0f, box.top);
			break;

		case TextAlign::right:
			m_sf_text.setPosition(box.left + box.width - m_sf_text.getLocalBounds().width, box.top);
			break;
	}

	// draw the text and the box
	target.draw(m_sf_text);
	if (draw_box)
	{
		sf::RectangleShape shape;
		shape.setFillColor(sf::Color::Transparent);
		shape.setOutlineThickness(1.0f);
		shape.setPosition(box.left, box.top);
		shape.setSize(Vec2f(box.width, box.height));
		target.draw(shape);
	}
}

void TextBox::adjust_box_height()
{
	m_sf_text.setString(this->wrap_text());
	box.height = m_sf_text.getLocalBounds().height;
}

std::string TextBox::wrap_text() const
{
	// update the local bounds, so we can use them in the calculation below.
	m_sf_text.setString(text);

	// calculate where to insert newlines
	std::string wrapped_string = text;
	const f32 box_to_bounds_ratio = box.width / m_sf_text.getLocalBounds().width;
	const u32 insert_newline_step = box_to_bounds_ratio * text.size();

	if (insert_newline_step == 0)
	{
		return text;
	}

	for (
		u32 insert_index = insert_newline_step;
		insert_index < wrapped_string.size();
		insert_index += insert_newline_step + 1)
	{
		// if there is a space or tab at the current insert location, replace it with a newline
		if (wrapped_string[insert_index] == ' ' || wrapped_string[insert_index] == '\t')
		{
			wrapped_string[insert_index] = '\n';
		}
		// only insert a newline if there isn't already one
		else if (wrapped_string[insert_index] != '\n')
		{
			wrapped_string.insert(wrapped_string.begin() + insert_index, 1, '\n');
		}
	}

	return wrapped_string;
}

}