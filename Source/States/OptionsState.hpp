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
	void on_enter(GameData &data) override;
	void update(GameData &data) override;
	void render(GameData &data) const override;

private:
	UI::TextBox m_music_vol_tb;
	UI::Slider m_music_vol_slider;
	UI::TextBox m_sound_vol_tb;
	UI::Slider m_sound_vol_slider;
	UI::Button m_back_btn;
};