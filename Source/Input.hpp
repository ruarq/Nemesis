#pragma once

#include <array>

#include <SFML/Graphics.hpp>

#include "Types.hpp"

class Input final
{
public:
	/**
	 * @brief update input
	 */
	static void Update();

	/**
	 * @brief handle key event
	 */
	static void HandleKeyEvent(const sf::Event &keyEvent);

	/**
	 * @brief check wether a ceratin key was pressed or not
	 */
	static bool Pressed(const sf::Keyboard::Key key);

	/**
	 * @brief check wether a ceratin key is held down or not
	 */
	static bool Down(const sf::Keyboard::Key key);

	/**
	 * @brief check wether a ceratin key was released or not
	 */
	static bool Released(const sf::Keyboard::Key key);

	/**
	 * @brief handle mouse event
	 */
	static void HandleMouseEvent(const sf::Event &mouseEvent);

	/**
	 * @brief check wether a ceratin button was pressed or not
	 */
	static bool Pressed(const sf::Mouse::Button button);

	/**
	 * @brief check wether a ceratin button is held down or not
	 */
	static bool Down(const sf::Mouse::Button button);

	/**
	 * @brief check wether a ceratin button was released or not
	 */
	static bool Released(const sf::Mouse::Button button);

	/**
	 * @return returns true if any key or button is pressed.
	 */
	static bool Any();

private:
	static std::array<bool, sf::Keyboard::KeyCount> keys;
	static std::array<bool, sf::Keyboard::KeyCount> prevKeys;

	static std::array<bool, sf::Mouse::ButtonCount> buttons;
	static std::array<bool, sf::Mouse::ButtonCount> prevButtons;
};