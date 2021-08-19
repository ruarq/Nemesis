#include "CreditState.hpp"

using namespace std::string_literals;

void CreditState::on_enter(GameData &data)
{
	// Load the credits font
	UI::Fonts::change("FreeMono.ttf");

	// play the happy music again
	gAudioSystem->play_music("happy", true);

	// needed for the fade later on
	on_enter_music_volume = gAudioSystem->get_music_volume();

	// set up text box (without text)
	m_credits.wrapped_text = false;
	m_credits.text_align = UI::TextAlign::left;
	m_credits.box.width = data.window.getSize().x;
	m_credits.box.top = data.window.getSize().y;

	// load the Credits.txt file
	const std::string filename = Data::Other::path("Credits.txt");
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

void CreditState::update(GameData &data)
{
	m_credits.box.top -= scroll_speed * gTime->dt();

	m_credits.adjust_box_height();
	if (m_credits.box.top + m_credits.box.height < 0.0f || gInput->any())
	{
		is_finished = true;
	}

	// fade the music
	if (m_credits.box.top + m_credits.box.height < music_fade)
	{
		const float volume = ((m_credits.box.top + m_credits.box.height) / music_fade) * on_enter_music_volume;
		if (volume >= 0.0f && volume <= 100.0f)
		{
			gAudioSystem->set_music_volume(volume);
		}
	}
}

void CreditState::render(GameData &data) const
{
	data.window.draw(m_credits);
}