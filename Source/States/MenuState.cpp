#include "MenuState.hpp"

#include "PlayingState.hpp"
#include "OptionsState.hpp"
#include "CreditState.hpp"

void MenuState::OnEnter()
{
	Audio::PlayMusic("happy", true);

	m_title.text = "NEMESIS";
	m_title.box = UI::Pos::Centered(Vec2f(200.0f, 50.0f), Vec2f(0.0f, -120.0f));
	m_title.textAlign = UI::TextAlign::Centered;

	m_buttons[MENUSTATE_PLAY_BTN].text = "PLAY";
	m_buttons[MENUSTATE_PLAY_BTN].box = UI::Pos::Centered(Vec2f(200.0f, 50.0f), Vec2f(0.0f, -60.0f));
	m_buttons[MENUSTATE_PLAY_BTN].textAlign = UI::TextAlign::Centered;

	m_buttons[MENUSTATE_OPTIONS_BTN].text = "OPTIONS";
	m_buttons[MENUSTATE_OPTIONS_BTN].box = UI::Pos::Centered(Vec2f(200.0f, 50.0f));
	m_buttons[MENUSTATE_OPTIONS_BTN].textAlign = UI::TextAlign::Centered;

	m_buttons[MENUSTATE_QUIT_BTN].text = "QUIT";
	m_buttons[MENUSTATE_QUIT_BTN].box = UI::Pos::Centered(Vec2f(200.0f, 50.0f), Vec2f(0.0f, 60.0f));
	m_buttons[MENUSTATE_QUIT_BTN].textAlign = UI::TextAlign::Centered;
}

void MenuState::Update()
{
	// draw box around hovered button
	for (UI::Button &button : m_buttons)
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

void MenuState::Render(sf::RenderWindow &window) const
{
	UI::BeginRender();
	window.draw(m_title);
	
	for (const UI::Button &button : m_buttons)
	{
		window.draw(button);
	}
	UI::EndRender();
}

GameState::Ptr MenuState::NextState()
{
	if (m_buttons[MENUSTATE_PLAY_BTN].IsPressed())
	{
		return GameState::Ptr(new PlayingState());
	}
	else if (m_buttons[MENUSTATE_OPTIONS_BTN].IsPressed())
	{
		return GameState::Ptr(new OptionsState());
	}
	else if (m_buttons[MENUSTATE_QUIT_BTN].IsPressed())
	{
		return GameState::Ptr(new CreditState());
	}

	return nullptr;
}