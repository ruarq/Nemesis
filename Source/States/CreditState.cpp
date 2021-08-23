#include "CreditState.hpp"

using namespace std::string_literals;

void CreditState::OnEnter()
{
	// play the happy music again
	Audio::PlayMusic("happy", true);

	// needed for the fade later on
	onEnterMusicVolume = Audio::MusicVolume();

	// set up text box (without text)
	credits.wrappedText = false;
	credits.textAlign = UI::TextAlign::Left;
	credits.box.width = game->window.getSize().x;
	credits.box.top = game->window.getSize().y;

	// load the Credits.txt file
	const std::string filename = Data::Other::Path("Credits.txt");
	std::ifstream file(filename);
	std::string line;
	
	if (!file.is_open())
	{
		credits.text = "[CreditState] => Couldn't open \""s + filename + "\""s;
		return;
	}

	while (std::getline(file, line))
	{
		credits.text += line + "\n";
	}
}

void CreditState::Update()
{
	credits.box.top -= scrollSpeed * Time::Dt();

	credits.AdjustBoxHeight();
	if (credits.box.top + credits.box.height < 0.0f || Input::Any())
	{
		game->isRunning = false;
	}

	// fade the music
	if (credits.box.top + credits.box.height < musicFade)
	{
		const float volume = ((credits.box.top + credits.box.height) / musicFade) * onEnterMusicVolume;
		if (volume >= 0.0f && volume <= 100.0f)
		{
			Audio::SetMusicVolume(volume);
		}
	}
}

void CreditState::Render() const
{
	UI::BeginRender();
	game->window.draw(credits);
	UI::EndRender();
}

GameState::Ptr CreditState::NextState()
{
	return nullptr;
}