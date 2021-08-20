#include "AudioSystem.hpp"

sf_Music_Ptr AudioSystem::m_currentMusic;
std::unordered_map<std::string, sf_Music_Ptr> AudioSystem::m_musicFiles;
f32 AudioSystem::m_musicVolume = 1.0f, AudioSystem::m_soundVolume = 1.0f;

AudioSystem::AudioSystem()
{
	Config audioConfig;
	const std::string filename = Data::Config::Path("Audio.cfg");

	if (!audioConfig.LoadFromFile(filename))
	{
		std::cout << "[AudioSystem] => Couldn't load \"" << filename << "\": continuing with default values.\n";
		return;
	}

	// read the values fromthe config
	m_musicVolume = audioConfig.GetValue<f32>("music_volume") * 100.0f;
	m_soundVolume = audioConfig.GetValue<f32>("sound_volume") * 100.0f;
}

AudioSystem::~AudioSystem()
{
	const std::string filename = Data::Config::Path("Audio.cfg");
	std::ofstream configFile(filename);

	if (!configFile.is_open())
	{
		std::cout << "[AudioSystem] => Couldn't save attributes to \"" << filename << "\"\n";
		return;
	}

	configFile << "music_volume " << (std::round(m_musicVolume) / 100.0f) << "\n";
	configFile << "sound_volume " << (std::round(m_soundVolume) / 100.0f) << "\n";
}

bool AudioSystem::LoadMusic(const std::string &name, const std::string &filename)
{
	using namespace std::string_literals;

	sf_Music_Ptr music(new sf::Music());
	if (!music->openFromFile(filename))
	{
		std::cout << "[AudioSystem] => Couldn't load audio file \""s << filename << "\"\n";
		return false;
	}

	m_musicFiles.emplace(name, std::move(music));
	return true;
}

bool AudioSystem::PlayMusic(const std::string &name, const bool loop)
{
	if (m_musicFiles.find(name) != m_musicFiles.end())
	{
		if (m_currentMusic)
		{
			m_currentMusic->stop();
		}

		// if the music is already playing do nothing
		if (m_musicFiles.at(name) == m_currentMusic)
		{
			// but update the loop
			m_currentMusic->setLoop(loop);
			return true;
		}

		m_currentMusic = m_musicFiles.at(name);
		m_currentMusic->setVolume(m_musicVolume);
		m_currentMusic->setLoop(loop);
		m_currentMusic->play();
		return true;
	}
	else
	{
		std::cout << "[AudioSystem] => Couldn't play audio file named \"" << name << "\"\n"; 
		return false;
	}
}

void AudioSystem::SetMusicVolume(const f32 volume)
{
	m_musicVolume = volume;
	
	if (m_currentMusic)
	{
		m_currentMusic->setVolume(volume);
	}
}

void AudioSystem::SetSoundVolume(const f32 volume)
{
	m_soundVolume = volume;
}

f32 AudioSystem::MusicVolume()
{
	return m_musicVolume;
}

f32 AudioSystem::SoundVolume()
{
	return m_soundVolume;
}