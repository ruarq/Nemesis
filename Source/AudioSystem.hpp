#pragma once

#include <iostream>
#include <unordered_map>
#include <string>
#include <cmath>
#include <memory>

#include <SFML/Audio.hpp>

#include "Data.hpp"
#include "Config.hpp"

// sf::Music::Ptr
using sf_Music_Ptr = std::shared_ptr<sf::Music>;

class AudioSystem final
{
public:
	AudioSystem();
	~AudioSystem();

public:
	/**
	 * @brief load a music file.
	 * @param name the alias for the music file, needed when playing the music etc.
	 * @param filename the filename of the music file.
	 * @return true if loading the music file was successful, false otherwise.
	 */
	static bool LoadMusic(const std::string &name, const std::string &filename);

	/**
	 * @brief play a music file.
	 * @param name the alias given to the music file when loading it.
	 * @param loop wether to play the file in loop or not
	 * @return true if the music is playing, false it not.
	 */
	static bool PlayMusic(const std::string &name, const bool loop = false);

	static void SetMusicVolume(const f32 volume);
	static void SetSoundVolume(const f32 volume);

	static f32 MusicVolume();
	static f32 SoundVolume();

private:
	static sf_Music_Ptr m_currentMusic;
	static std::unordered_map<std::string, sf_Music_Ptr> m_musicFiles;
	static f32 m_musicVolume, m_soundVolume;
};