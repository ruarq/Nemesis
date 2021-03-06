#pragma once

#include <fstream>

#include "../UI/TextBox.hpp"
#include "../UI/Positioning.hpp"
#include "../UI/Fonts.hpp"
#include "../UI/UI.hpp"
#include "../Types.hpp"
#include "../GameState.hpp"
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
	void OnEnter() override;
	void Update() override;
	void Render() const override;

	GameState::Ptr NextState() override;

private:
	UI::TextBox credits;
	f32 onEnterMusicVolume;
};