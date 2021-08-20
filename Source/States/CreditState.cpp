#include "CreditState.hpp"

using namespace std::string_literals;

void CreditState::OnEnter(GameData &data)
{
	// Load the credits font
	UI::Fonts::Change("FreeMono.ttf");

	// play the happy music again
	Audio::PlayMusic("happy", true);

	// needed for the fade later on
	m_onEnterMusicVolume = Audio::MusicVolume();

	// set up text box (without text)
	m_credits.wrappedText = false;
	m_credits.textAlign = UI::TextAlign::Left;
	m_credits.box.width = data.window.getSize().x;
	m_credits.box.top = data.window.getSize().y;

	// load the Credits.txt file
	const std::string filename = Data::Other::Path("Credits.txt");
	std::ifstream file(filename);
	std::string line;

	if (!file.is_open())
	{
		m_credits.text = "[CreditState] => Couldn't open \""s + filename + "\""s;
		return;
	}

	while (std::getline(file, line))
	{
		m_credits.text += line + "\n";
	}
}

void CreditState::Update(GameData &data)
{
	m_credits.box.top -= scrollSpeed * Time::Dt();

	m_credits.AdjustBoxHeight();
	if (m_credits.box.top + m_credits.box.height < 0.0f || Input::Any())
	{
		data.isRunning = false;
	}

	// fade the music
	if (m_credits.box.top + m_credits.box.height < musicFade)
	{
		const float volume = ((m_credits.box.top + m_credits.box.height) / musicFade) * m_onEnterMusicVolume;
		if (volume >= 0.0f && volume <= 100.0f)
		{
			Audio::SetMusicVolume(volume);
		}
	}
}

void CreditState::Render(GameData &data) const
{
	data.window.draw(m_credits);
}

GameState::Ptr CreditState::NextState(GameData &data)
{
	return nullptr;
}