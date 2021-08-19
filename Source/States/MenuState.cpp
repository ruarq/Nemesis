#include "MenuState.hpp"

#include "PlayingState.hpp"
#include "OptionsState.hpp"
#include "CreditState.hpp"

void MenuState::on_enter(GameData &data)
{
	gAudioSystem->play_music("happy", true);

	m_title.text = "NEMESIS";
	m_title.box = UI::Pos::centered(data, Vec2f(200.0f, 50.0f), Vec2f(0.0f, -120.0f));
	m_title.text_align = UI::TextAlign::centered;

	m_buttons[MENUSTATE_PLAY_BTN].text = "PLAY";
	m_buttons[MENUSTATE_PLAY_BTN].box = UI::Pos::centered(data, Vec2f(200.0f, 50.0f), Vec2f(0.0f, -60.0f));
	m_buttons[MENUSTATE_PLAY_BTN].text_align = UI::TextAlign::centered;

	m_buttons[MENUSTATE_OPTIONS_BTN].text = "OPTIONS";
	m_buttons[MENUSTATE_OPTIONS_BTN].box = UI::Pos::centered(data, Vec2f(200.0f, 50.0f));
	m_buttons[MENUSTATE_OPTIONS_BTN].text_align = UI::TextAlign::centered;

	m_buttons[MENUSTATE_QUIT_BTN].text = "QUIT";
	m_buttons[MENUSTATE_QUIT_BTN].box = UI::Pos::centered(data, Vec2f(200.0f, 50.0f), Vec2f(0.0f, 60.0f));
	m_buttons[MENUSTATE_QUIT_BTN].text_align = UI::TextAlign::centered;
}

void MenuState::update(GameData &data)
{
	// draw box around hovered button
	for (UI::Button &button : m_buttons)
	{
		if (button.is_hovered(data))
		{
			button.draw_box = true;
		}
		else
		{
			button.draw_box = false;
		}
	}

	if (m_buttons[MENUSTATE_PLAY_BTN].is_pressed(data))
	{
		data.state_queue.push(PlayingState::Ptr(new PlayingState()));
		is_finished = true;
	}
	else if (m_buttons[MENUSTATE_OPTIONS_BTN].is_pressed(data))
	{
		data.state_queue.push(OptionsState::Ptr(new OptionsState()));
		data.state_queue.push(MenuState::Ptr(new MenuState()));
		is_finished = true;
	}
	else if (m_buttons[MENUSTATE_QUIT_BTN].is_pressed(data))
	{
		data.state_queue.push(CreditState::Ptr(new CreditState()));
		is_finished = true;
	}
}

void MenuState::render(GameData &data) const
{
	data.window.draw(m_title);
	
	for (const UI::Button &button : m_buttons)
	{
		data.window.draw(button);
	}
}