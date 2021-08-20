#include "AudioSystem.hpp"

AudioSystem::AudioSystem()
{
	Config audio_config;
	const std::string filename = Data::Config::path("Audio.cfg");

	if (!audio_config.load_from_file(filename))
	{
		std::cout << "[AudioSystem] => Couldn't load \"" << filename << "\": continuing with default values.\n";
		return;
	}

	// read the values fromthe config
	m_music_volume = audio_config.get_value<f32>("music_volume") * 100.0f;
	m_sound_volume = audio_config.get_value<f32>("sound_volume") * 100.0f;
}

AudioSystem::~AudioSystem()
{
	const std::string filename = Data::Config::path("Audio.cfg");
	std::ofstream config_file(filename);

	if (!config_file.is_open())
	{
		std::cout << "[AudioSystem] => Couldn't save attributes to \"" << filename << "\"\n";
		return;
	}

	config_file << "music_volume " << (std::round(m_music_volume) / 100.0f) << "\n";
	config_file << "sound_volume " << (std::round(m_sound_volume) / 100.0f) << "\n";
}

bool AudioSystem::load_music(const std::string &name, const std::string &filename)
{
	using namespace std::string_literals;

	sfMusicPtr music(new sf::Music());
	if (!music->openFromFile(filename))
	{
		std::cout << "[AudioSystem] => Couldn't load audio file \""s << filename << "\"\n";
		return false;
	}

	m_music_files.emplace(name, std::move(music));
	return true;
}

bool AudioSystem::play_music(const std::string &name, const bool loop)
{
	if (m_music_files.find(name) != m_music_files.end())
	{
		if (m_current_music)
		{
			m_current_music->stop();
		}

		// if the music is already playing do nothing
		if (m_music_files.at(name) == m_current_music)
		{
			// but update the loop
			m_current_music->setLoop(loop);
			return true;
		}

		m_current_music = m_music_files.at(name);
		m_current_music->setVolume(m_music_volume);
		m_current_music->setLoop(loop);
		m_current_music->play();
		return true;
	}
	else
	{
		std::cout << "[AudioSystem] => Couldn't play audio file named \"" << name << "\"\n"; 
		return false;
	}
}

void AudioSystem::set_music_volume(const f32 volume)
{
	m_music_volume = volume;
	
	if (m_current_music)
	{
		m_current_music->setVolume(volume);
	}
}

void AudioSystem::set_sound_volume(const f32 volume)
{
	m_sound_volume = volume;
}

f32 AudioSystem::get_music_volume() const
{
	return m_music_volume;
}

f32 AudioSystem::get_sound_volume() const
{
	return m_sound_volume;
}