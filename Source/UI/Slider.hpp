#pragma once

#include <SFML/Graphics.hpp>

#include "../Vec2.hpp"
#include "../Input.hpp"
#include "UI.hpp"

namespace UI
{

class Slider final : public sf::Drawable
{
public:
	void Update();
	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
	f32 Value() const;
	void SetValue(const f32 value);

public:
	sf::FloatRect rect;

	f32 minValue = 0.0f;
	f32 maxValue = 1.0f;

private:
	const f32 m_normalMin = 0.0f, m_normalMax = 1.0f;
	f32 m_value = 1.0f;
};

}