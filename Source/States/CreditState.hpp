#pragma once

#include <fstream>

#include "../UI/TextBox.hpp"
#include "../UI/Positioning.hpp"
#include "../UI/Fonts.hpp"
#include "../Types.hpp"
#include "../GameState.hpp"
#include "../GameData.hpp"
#include "../Data.hpp"
#include "../Time.hpp"
#include "../AudioSystem.hpp"
#include "../Input.hpp"

class CreditState final : public GameState
{
public:
	using Ptr = std::unique_ptr<CreditState>;

public:
	static constexpr f32 scroll_speed = 50.0f;
	static constexpr f32 music_fade = 250.0f; // the amount of height of the text box that need to be left on screen for the music to start to fade.

public:
	void on_enter(GameData &data) override;
	void update(GameData &data) override;
	void render(GameData &data) const override;

private:
	UI::TextBox m_credits;
	f32 on_enter_music_volume;
};