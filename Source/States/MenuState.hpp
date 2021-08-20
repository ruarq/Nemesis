#pragma once

#include <array>

#include "../UI/TextBox.hpp"
#include "../UI/Button.hpp"
#include "../UI/Positioning.hpp"
#include "../GameState.hpp"
#include "../Game.hpp"
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
	void OnEnter(GameData &data) override;
	void Update(GameData &data) override;
	void Render(GameData &data) const override;

	GameState::Ptr NextState(GameData &data) override;

public:
	UI::TextBox m_title;
	std::array<UI::Button, 3> m_buttons;
};