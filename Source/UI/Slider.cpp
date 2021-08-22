#include "Slider.hpp"

namespace UI
{

void Slider::Update()
{
	const Vec2f mousePos = sf::Mouse::getPosition(_RenderWindow());
	sf::FloatRect collisionRect = rect;
	collisionRect.height *= 2.0f;
	collisionRect.top -= collisionRect.height / 2.0f;
	if (Input::Down(sf::Mouse::Button::Left) && collisionRect.contains(mousePos))
	{
		value = (mousePos.x - rect.left) / rect.width;
		
		if (value > normalMax)
		{
			value = normalMax;
		}
		else if (value < normalMin)
		{
			value = normalMin;
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
	button.setPosition(rect.left + value * rect.width, rect.top);
	button.setOrigin(button.getRadius(), button.getRadius());

	target.draw(slider);
	target.draw(button);
}

float Slider::Value() const
{
	return (maxValue - minValue) * value + minValue;
}

void Slider::SetValue(const f32 value)
{
	this->value = (value - minValue) / (maxValue - minValue);
}

}