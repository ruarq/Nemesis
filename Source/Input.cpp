#include "Input.hpp"

void Input::update()
{
	m_prev_keys = m_keys;
	m_prev_buttons = m_buttons;
}

void Input::handle_key_event(const sf::Event &event)
{
	m_prev_keys = m_keys;

	if (event.type == sf::Event::KeyPressed)
	{
		m_keys[event.key.code] = true;
	}
	else if (event.type == sf::Event::KeyReleased)
	{
		m_keys[event.key.code] = false;
	}
}

bool Input::pressed(const sf::Keyboard::Key key) const
{
	return m_prev_keys[key] == false && m_keys[key] == true;
}

bool Input::down(const sf::Keyboard::Key key) const
{
	return m_keys[key] == true;
}

bool Input::released(const sf::Keyboard::Key key) const
{
	return m_prev_keys[key] == true && m_keys[key] == false;
}

void Input::handle_mouse_event(const sf::Event &event)
{
	m_prev_buttons = m_buttons;

	if (event.type == sf::Event::MouseButtonPressed)
	{
		m_buttons[event.mouseButton.button] = true;
	}
	else if (event.type == sf::Event::MouseButtonReleased)
	{
		m_buttons[event.mouseButton.button] = false;
	}
}

bool Input::pressed(const sf::Mouse::Button button) const
{
	return m_prev_buttons[button] == false && m_buttons[button] == true;
}

bool Input::down(const sf::Mouse::Button button) const
{
	return m_buttons[button];
}

bool Input::released(const sf::Mouse::Button button) const
{
	return m_prev_buttons[button] == true && m_buttons[button] == false;
}

bool Input::any() const
{
	for (const bool key : m_keys)
	{
		if (key)
		{
			return true;
		}
	}

	for (const bool button : m_buttons)
	{
		if (button)
		{
			return true;
		}
	}

	return false;
}