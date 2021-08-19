#pragma once

#include <iostream>
#include <queue>

#include <SFML/Graphics.hpp>

#include "UI/Fonts.hpp"
#include "GameData.hpp"
#include "GameState.hpp"
#include "Data.hpp"
#include "Config.hpp"
#include "Time.hpp"
#include "AudioSystem.hpp"
#include "Input.hpp"
#include "Singleton.hpp"
#include "Room.hpp"

class Game final
{
public:
	void run();

private:
	void create_window();
	void load_data();
	void handle_events();

public:
	GameData data;
};