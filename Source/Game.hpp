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
#include "Audio.hpp"
#include "Input.hpp"

class Game final
{
public:
	void Run();

private:
	void CreateWindow();
	void LoadData();
	void HandleEvents();

public:
	GameData data;
};