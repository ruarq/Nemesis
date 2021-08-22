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
	void Render() const override;

	GameState::Ptr NextState() override;

private:
	UI::TextBox title;
	std::array<UI::Button, 3> buttons;
};