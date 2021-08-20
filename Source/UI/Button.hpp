#pragma once

#include <SFML/Graphics.hpp>

#include "../Vec2.hpp"
#include "../Input.hpp"
#include "TextBox.hpp"
#include "UI.hpp"

namespace UI
{

class Button final : public TextBox
{
public:
	bool IsHovered() const;
	bool IsPressed() const;
};

}