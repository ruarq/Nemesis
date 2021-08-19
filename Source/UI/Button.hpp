#pragma once

#include <SFML/Graphics.hpp>

#include "../Vec2.hpp"
#include "../Input.hpp"
#include "../GameData.hpp"
#include "TextBox.hpp"

namespace UI
{

class Button final : public TextBox
{
public:
	bool is_hovered(const GameData &data) const;
	bool is_pressed(const GameData &data) const;
};

}