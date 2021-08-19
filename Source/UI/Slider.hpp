#pragma once

#include <SFML/Graphics.hpp>

#include "../Vec2.hpp"
#include "../Input.hpp"
#include "../GameData.hpp"

namespace UI
{

class Slider final : public sf::Drawable
{
public:
	void update(const GameData &data);
	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
	f32 value() const;
	void set_value(const f32 value);

public:
	sf::FloatRect rect;

	f32 min_value = 0.0f;
	f32 max_value = 1.0f;

private:
	const f32 m_normal_min = 0.0f, m_normal_max = 1.0f;
	f32 m_value = 1.0f;
};

}