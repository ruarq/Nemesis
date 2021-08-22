#include "OptionsState.hpp"

#include "MenuState.hpp"

void OptionsState::OnEnter()
{
	musicVolTextBox.text = "MUSIC VOL";
	musicVolTextBox.box = UI::Pos::Centered(Vec2f(200.0f, 10.0f), Vec2f(-100.0f, -50.0f));
	musicVolTextBox.fontSize = 15.0f;

	musicVolSlider.minValue = 0.0f;
	musicVolSlider.maxValue = 100.0f;
	musicVolSlider.SetValue(Audio::MusicVolume());
	musicVolSlider.rect = UI::Pos::Centered(Vec2f(200.0f, 10.0f), Vec2f(0.0f, -40.0f));

	soundVolTextBox.text = "SOUND VOL";
	soundVolTextBox.box = UI::Pos::Centered(Vec2f(200.0f, 10.0f), Vec2f(-100.0f, -10.0f));
	soundVolTextBox.fontSize = 15.0f;

	soundVolSlider.minValue = 0.0f;
	soundVolSlider.maxValue = 100.0f;
	soundVolSlider.rect = UI::Pos::Centered(Vec2f(200.0f, 10.0f));

	backButton.text = "BACK";
	backButton.textAlign = UI::TextAlign::Centered;
	backButton.box = UI::Pos::Centered(Vec2f(200.0f, 50.0f), Vec2f(0.0f, 40.0f));
}

void OptionsState::Update()
{
	musicVolSlider.Update();
	soundVolSlider.Update();

	Audio::SetMusicVolume(musicVolSlider.Value());

	if (backButton.IsHovered())
	{
		backButton.drawBox = true;
	}
	else
	{
		backButton.drawBox = false;
	}
}

void OptionsState::Render() const
{
	UI::BeginRender();
	game->window.draw(musicVolTextBox);
	game->window.draw(musicVolSlider);
	game->window.draw(soundVolTextBox);
	game->window.draw(soundVolSlider);
	game->window.draw(backButton);
	UI::EndRender();
}

GameState::Ptr OptionsState::NextState()
{
	if (backButton.IsPressed())
	{
		return GameState::Ptr(new MenuState());
	}

	return nullptr;
}