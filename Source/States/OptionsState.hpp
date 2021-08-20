#pragma once

#include "../UI/Slider.hpp"
#include "../UI/TextBox.hpp"
#include "../UI/Button.hpp"
#include "../UI/Positioning.hpp"
#include "../GameState.hpp"
#include "../GameData.hpp"
#include "../Input.hpp"
#include "../AudioSystem.hpp"

class OptionsState final : public GameState
{
public:
	using Ptr = std::unique_ptr<OptionsState>;

public:
	void OnEnter(GameData &data) override;
	void Update(GameData &data) override;
	void Render(GameData &data) const override;

private:
	UI::TextBox m_musicVolTextBox;
	UI::Slider m_musicVolSlider;
	UI::TextBox m_soundVolTextBox;
	UI::Slider m_soundVolSlider;
	UI::Button m_backButton;
};