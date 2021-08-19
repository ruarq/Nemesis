#pragma once

#include <iostream>
#include <unordered_map>
#include <string>
#include <cmath>
#include <memory>

#include <SFML/Audio.hpp>

#include "Singleton.hpp"
#include "Data.hpp"
#include "Config.hpp"

#define gAudioSystem Singleton<AudioSystem>::get()

class AudioSystem final
{
public:
	using sfMusicPtr = std::shared_ptr<sf::Music>;

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
	bool load_music(const std::string &name, const std::string &filename);

	/**
	 * @brief play a music file.
	 * @param name the alias given to the music file when loading it.
	 * @param loop wether to play the file in loop or not
	 * @return true if the music is playing, false it not.
	 */
	bool play_music(const std::string &name, const bool loop = false);

	void set_music_volume(const f32 volume);
	void set_sound_volume(const f32 volume);

	f32 get_music_volume() const;
	f32 get_sound_volume() const;

private:
	sfMusicPtr m_current_music;
	std::unordered_map<std::string, sfMusicPtr> m_music_files;
	f32 m_music_volume = 1.0f, m_sound_volume = 1.0f;
};