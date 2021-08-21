#pragma once

#include "../UI/Slider.hpp"
#include "../UI/TextBox.hpp"
#include "../UI/Button.hpp"
#include "../UI/Positioning.hpp"
#include "../UI/UI.hpp"
#include "../GameState.hpp"
#include "../Input.hpp"
#include "../Audio.hpp"

class OptionsState final : public GameState
{
public:
	using Ptr = std::unique_ptr<OptionsState>;

public:
	void OnEnter() override;
	void Update() override;
	void Render() const override;

	GameState::Ptr NextState() override;

private:
	UI::TextBox m_musicVolTextBox;
	UI::Slider m_musicVolSlider;
	UI::TextBox m_soundVolTextBox;
	UI::Slider m_soundVolSlider;
	UI::Button m_backButton;
};