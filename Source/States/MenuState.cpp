#include "MenuState.hpp"

#include "PlayingState.hpp"
#include "OptionsState.hpp"
#include "CreditState.hpp"

void MenuState::OnEnter(GameData &data)
{
	AudioSystem::PlayMusic("happy", true);

	m_title.text = "NEMESIS";
	m_title.box = UI::Pos::Centered(data, Vec2f(200.0f, 50.0f), Vec2f(0.0f, -120.0f));
	m_title.textAlign = UI::TextAlign::Centered;

	m_buttons[MENUSTATE_PLAY_BTN].text = "PLAY";
	m_buttons[MENUSTATE_PLAY_BTN].box = UI::Pos::Centered(data, Vec2f(200.0f, 50.0f), Vec2f(0.0f, -60.0f));
	m_buttons[MENUSTATE_PLAY_BTN].textAlign = UI::TextAlign::Centered;

	m_buttons[MENUSTATE_OPTIONS_BTN].text = "OPTIONS";
	m_buttons[MENUSTATE_OPTIONS_BTN].box = UI::Pos::Centered(data, Vec2f(200.0f, 50.0f));
	m_buttons[MENUSTATE_OPTIONS_BTN].textAlign = UI::TextAlign::Centered;

	m_buttons[MENUSTATE_QUIT_BTN].text = "QUIT";
	m_buttons[MENUSTATE_QUIT_BTN].box = UI::Pos::Centered(data, Vec2f(200.0f, 50.0f), Vec2f(0.0f, 60.0f));
	m_buttons[MENUSTATE_QUIT_BTN].textAlign = UI::TextAlign::Centered;
}

void MenuState::Update(GameData &data)
{
	// draw box around hovered button
	for (UI::Button &button : m_buttons)
	{
		if (button.IsHovered(data))
		{
			button.drawBox = true;
		}
		else
		{
			button.drawBox = false;
		}
	}

	if (m_buttons[MENUSTATE_PLAY_BTN].IsPressed(data))
	{
		data.states.push(PlayingState::Ptr(new PlayingState()));
		isFinished = true;
	}
	else if (m_buttons[MENUSTATE_OPTIONS_BTN].IsPressed(data))
	{
		data.states.push(OptionsState::Ptr(new OptionsState()));
		data.states.push(MenuState::Ptr(new MenuState()));
		isFinished = true;
	}
	else if (m_buttons[MENUSTATE_QUIT_BTN].IsPressed(data))
	{
		data.states.push(CreditState::Ptr(new CreditState()));
		isFinished = true;
	}
}

void MenuState::Render(GameData &data) const
{
	data.window.draw(m_title);
	
	for (const UI::Button &button : m_buttons)
	{
		data.window.draw(button);
	}
}