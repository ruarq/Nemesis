#include "OptionsState.hpp"

#include "MenuState.hpp"

void OptionsState::OnEnter()
{
	m_musicVolTextBox.text = "MUSIC VOL";
	m_musicVolTextBox.box = UI::Pos::Centered(Vec2f(200.0f, 10.0f), Vec2f(-100.0f, -50.0f));
	m_musicVolTextBox.fontSize = 15.0f;

	m_musicVolSlider.minValue = 0.0f;
	m_musicVolSlider.maxValue = 100.0f;
	m_musicVolSlider.SetValue(Audio::MusicVolume());
	m_musicVolSlider.rect = UI::Pos::Centered(Vec2f(200.0f, 10.0f), Vec2f(0.0f, -40.0f));

	m_soundVolTextBox.text = "SOUND VOL";
	m_soundVolTextBox.box = UI::Pos::Centered(Vec2f(200.0f, 10.0f), Vec2f(-100.0f, -10.0f));
	m_soundVolTextBox.fontSize = 15.0f;

	m_soundVolSlider.minValue = 0.0f;
	m_soundVolSlider.maxValue = 100.0f;
	m_soundVolSlider.rect = UI::Pos::Centered(Vec2f(200.0f, 10.0f));

	m_backButton.text = "BACK";
	m_backButton.textAlign = UI::TextAlign::Centered;
	m_backButton.box = UI::Pos::Centered(Vec2f(200.0f, 50.0f), Vec2f(0.0f, 40.0f));
}

void OptionsState::Update()
{
	m_musicVolSlider.Update();
	m_soundVolSlider.Update();

	Audio::SetMusicVolume(m_musicVolSlider.Value());

	if (m_backButton.IsHovered())
	{
		m_backButton.drawBox = true;
	}
	else
	{
		m_backButton.drawBox = false;
	}
}

void OptionsState::Render(sf::RenderWindow &window) const
{
	UI::BeginRender();
	window.draw(m_musicVolTextBox);
	window.draw(m_musicVolSlider);
	window.draw(m_soundVolTextBox);
	window.draw(m_soundVolSlider);
	window.draw(m_backButton);
	UI::EndRender();
}

GameState::Ptr OptionsState::NextState()
{
	if (m_backButton.IsPressed())
	{
		return GameState::Ptr(new MenuState());
	}

	return nullptr;
}