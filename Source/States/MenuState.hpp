#pragma once

#include <array>

#include "../UI/TextBox.hpp"
#include "../UI/Button.hpp"
#include "../UI/Positioning.hpp"
#include "../UI/UI.hpp"
#include "../GameState.hpp"
#include "../Audio.hpp"
#include "../Input.hpp"

#define MENUSTATE_PLAY_BTN 0
#define MENUSTATE_OPTIONS_BTN 1
#define MENUSTATE_QUIT_BTN 2

class MenuState final : public GameState
{
public:
	using Ptr = std::unique_ptr<MenuState>;

public:
	void OnEnter() override;
	void Update() override;
	void Render(sf::RenderWindow &window) const override;

	GameState::Ptr NextState() override;

public:
	UI::TextBox m_title;
	std::array<UI::Button, 3> m_buttons;
};