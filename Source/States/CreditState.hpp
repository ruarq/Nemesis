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
#include "../Audio.hpp"
#include "../Input.hpp"

class CreditState final : public GameState
{
public:
	using Ptr = std::unique_ptr<CreditState>;

public:
	static constexpr f32 scrollSpeed = 50.0f;
	static constexpr f32 musicFade = 250.0f; // the amount of height of the text box that need to be left on screen for the music to start to fade.

public:
	void OnEnter(GameData &data) override;
	void Update(GameData &data) override;
	void Render(GameData &data) const override;

	GameState::Ptr NextState(GameData &data) override;

private:
	UI::TextBox m_credits;
	f32 m_onEnterMusicVolume;
};