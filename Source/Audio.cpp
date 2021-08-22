#include "Audio.hpp"

sf_Music_Ptr Audio::currentMusic;
std::unordered_map<std::string, sf_Music_Ptr> Audio::musicFiles;
f32 Audio::musicVolume = 100.0f, Audio::soundVolume = 100.0f;

void Audio::Init()
{
	Config audioConfig;
	const std::string filename = Data::Config::Path("Audio.cfg");

	if (!audioConfig.LoadFromFile(filename))
	{
		return;
	}

	// read the values from the config
	musicVolume = audioConfig.GetValue<f32>("music_volume") * 100.0f;
	soundVolume = audioConfig.GetValue<f32>("sound_volume") * 100.0f;
}

void Audio::Shutdown()
{
	const std::string filename = Data::Config::Path("Audio.cfg");
	std::ofstream configFile(filename);

	if (!configFile.is_open())
	{
		std::cout << "[Audio] => Couldn't save attributes to \"" << filename << "\"\n";
		return;
	}

	configFile << "music_volume " << (std::round(musicVolume) / 100.0f) << "\n";
	configFile << "sound_volume " << (std::round(soundVolume) / 100.0f) << "\n";
}

bool Audio::LoadMusic(const std::string &name, const std::string &filename)
{
	using namespace std::string_literals;

	sf_Music_Ptr music(new sf::Music());
	if (!music->openFromFile(filename))
	{
		std::cout << "[Audio] => Couldn't load audio file \""s << filename << "\"\n";
		return false;
	}

	musicFiles.emplace(name, std::move(music));
	return true;
}

bool Audio::PlayMusic(const std::string &name, const bool loop)
{
	if (musicFiles.find(name) != musicFiles.end())
	{
		// if the music is already playing do nothing
		if (musicFiles.at(name) == currentMusic)
		{
			// but update the loop
			currentMusic->setLoop(loop);
			return true;
		}

		if (currentMusic)
		{
			currentMusic->stop();
		}

		currentMusic = musicFiles.at(name);
		currentMusic->setVolume(musicVolume);
		currentMusic->setLoop(loop);
		currentMusic->play();
		return true;
	}
	else
	{
		std::cout << "[Audio] => Couldn't play audio file named \"" << name << "\"\n"; 
		return false;
	}
}

void Audio::SetMusicVolume(const f32 volume)
{
	musicVolume = volume;
	
	if (currentMusic)
	{
		currentMusic->setVolume(volume);
	}
}

void Audio::SetSoundVolume(const f32 volume)
{
	soundVolume = volume;
}

f32 Audio::MusicVolume()
{
	return musicVolume;
}

f32 Audio::SoundVolume()
{
	return soundVolume;
}