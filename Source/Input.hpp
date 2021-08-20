#pragma once

#include <array>

#include <SFML/Graphics.hpp>

#include "Types.hpp"

class Input final
{
public:
	static void Update();

	static void HandleKeyEvent(const sf::Event &keyEvent);
	static bool Pressed(const sf::Keyboard::Key key);
	static bool Down(const sf::Keyboard::Key key);
	static bool Released(const sf::Keyboard::Key key);

	static void HandleMouseEvent(const sf::Event &mouseEvent);
	static bool Pressed(const sf::Mouse::Button button);
	static bool Down(const sf::Mouse::Button button);
	static bool Released(const sf::Mouse::Button button);

	/**
	 * @return returns true if any key or button is pressed.
	 */
	static bool Any();

private:
	static std::array<bool, sf::Keyboard::KeyCount> m_keys;
	static std::array<bool, sf::Keyboard::KeyCount> m_prevKeys;

	static std::array<bool, sf::Mouse::ButtonCount> m_buttons;
	static std::array<bool, sf::Mouse::ButtonCount> m_prevButtons;
};