#pragma once

#include <SFML/Graphics.hpp>

namespace UI
{

void Init(sf::RenderWindow &window);
sf::RenderWindow& _RenderWindow();

void BeginRender();
void EndRender();

}