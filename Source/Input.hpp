#pragma once

#include <array>

#include <SFML/Graphics.hpp>

#include "Singleton.hpp"
#include "Types.hpp"

#define gInput Singleton<Input>::get()

class Input final
{
public:
	void update();

	void handle_key_event(const sf::Event &key_event);
	bool pressed(const sf::Keyboard::Key key) const;
	bool down(const sf::Keyboard::Key key) const;
	bool released(const sf::Keyboard::Key key) const;

	void handle_mouse_event(const sf::Event &mouse_event);
	bool pressed(const sf::Mouse::Button button) const;
	bool down(const sf::Mouse::Button button) const;
	bool released(const sf::Mouse::Button button) const;

	/**
	 * @return returns true if any key or button is pressed.
	 */
	bool any() const;

private:
	std::array<bool, sf::Keyboard::KeyCount> m_keys;
	std::array<bool, sf::Keyboard::KeyCount> m_prev_keys;

	std::array<bool, sf::Mouse::ButtonCount> m_buttons;
	std::array<bool, sf::Mouse::ButtonCount> m_prev_buttons;
};