#include "Slider.hpp"

namespace UI
{

void Slider::update(const GameData &data)
{
	const Vec2f mouse_pos = sf::Mouse::getPosition(data.window);
	sf::FloatRect collision_rect = rect;
	collision_rect.height *= 2.0f;
	collision_rect.top -= collision_rect.height / 2.0f;
	if (gInput->down(sf::Mouse::Button::Left) && collision_rect.contains(mouse_pos))
	{
		m_value = (mouse_pos.x - rect.left) / rect.width;
		
		if (m_value > m_normal_max)
		{
			m_value = m_normal_max;
		}
		else if (m_value < m_normal_min)
		{
			m_value = m_normal_min;
		}
	}
}

void Slider::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	sf::RectangleShape slider;
	slider.setPosition(rect.left, rect.top);
	slider.setSize(Vec2f(rect.width, rect.height / 2.0f));
	slider.setOrigin(0.0f, slider.getSize().y / 2.0f);

	sf::CircleShape button;
	button.setRadius(rect.height);
	button.setPosition(rect.left + m_value * rect.width, rect.top);
	button.setOrigin(button.getRadius(), button.getRadius());

	target.draw(slider);
	target.draw(button);
}

float Slider::value() const
{
	return (max_value - min_value) * m_value + min_value;
}

void Slider::set_value(const f32 value)
{
	m_value = (value - min_value) / (max_value - min_value);
}

}