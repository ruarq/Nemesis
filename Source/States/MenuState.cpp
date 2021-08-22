#include "MenuState.hpp"

#include "PlayingState.hpp"
#include "OptionsState.hpp"
#include "CreditState.hpp"

void MenuState::OnEnter()
{
	Audio::PlayMusic("happy", true);

	title.text = "NEMESIS";
	title.box = UI::Pos::Centered(Vec2f(200.0f, 50.0f), Vec2f(0.0f, -120.0f));
	title.textAlign = UI::TextAlign::Centered;

	buttons[MENUSTATE_PLAY_BTN].text = "PLAY";
	buttons[MENUSTATE_PLAY_BTN].box = UI::Pos::Centered(Vec2f(200.0f, 50.0f), Vec2f(0.0f, -60.0f));
	buttons[MENUSTATE_PLAY_BTN].textAlign = UI::TextAlign::Centered;

	buttons[MENUSTATE_OPTIONS_BTN].text = "OPTIONS";
	buttons[MENUSTATE_OPTIONS_BTN].box = UI::Pos::Centered(Vec2f(200.0f, 50.0f));
	buttons[MENUSTATE_OPTIONS_BTN].textAlign = UI::TextAlign::Centered;

	buttons[MENUSTATE_QUIT_BTN].text = "QUIT";
	buttons[MENUSTATE_QUIT_BTN].box = UI::Pos::Centered(Vec2f(200.0f, 50.0f), Vec2f(0.0f, 60.0f));
	buttons[MENUSTATE_QUIT_BTN].textAlign = UI::TextAlign::Centered;
}

void MenuState::Update()
{
	// draw box around hovered button
	for (UI::Button &button : buttons)
	{
		if (button.IsHovered())
		{
			button.drawBox = true;
		}
		else
		{
			button.drawBox = false;
		}
	}
}

void MenuState::Render() const
{
	UI::BeginRender();
	game->window.draw(title);
	
	for (const UI::Button &button : buttons)
	{
		game->window.draw(button);
	}
	UI::EndRender();
}

GameState::Ptr MenuState::NextState()
{
	if (buttons[MENUSTATE_PLAY_BTN].IsPressed())
	{
		return GameState::Ptr(new PlayingState());
	}
	else if (buttons[MENUSTATE_OPTIONS_BTN].IsPressed())
	{
		return GameState::Ptr(new OptionsState());
	}
	else if (buttons[MENUSTATE_QUIT_BTN].IsPressed())
	{
		return GameState::Ptr(new CreditState());
	}

	return nullptr;
}