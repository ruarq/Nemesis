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
	const f32 normalMin = 0.0f, normalMax = 1.0f;
	f32 value = 1.0f;
};

}