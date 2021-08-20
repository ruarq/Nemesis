#include "Input.hpp"

std::array<bool, sf::Keyboard::KeyCount> Input::m_keys;
std::array<bool, sf::Keyboard::KeyCount> Input::m_prevKeys;

std::array<bool, sf::Mouse::ButtonCount> Input::m_buttons;
std::array<bool, sf::Mouse::ButtonCount> Input::m_prevButtons;

void Input::Update()
{
	m_prevKeys = m_keys;
	m_prevButtons = m_buttons;
}

void Input::HandleKeyEvent(const sf::Event &event)
{
	m_prevKeys = m_keys;

	if (event.type == sf::Event::KeyPressed)
	{
		m_keys[event.key.code] = true;
	}
	else if (event.type == sf::Event::KeyReleased)
	{
		m_keys[event.key.code] = false;
	}
}

bool Input::Pressed(const sf::Keyboard::Key key)
{
	return m_prevKeys[key] == false && m_keys[key] == true;
}

bool Input::Down(const sf::Keyboard::Key key)
{
	return m_keys[key] == true;
}

bool Input::Released(const sf::Keyboard::Key key)
{
	return m_prevKeys[key] == true && m_keys[key] == false;
}

void Input::HandleMouseEvent(const sf::Event &event)
{
	m_prevButtons = m_buttons;

	if (event.type == sf::Event::MouseButtonPressed)
	{
		m_buttons[event.mouseButton.button] = true;
	}
	else if (event.type == sf::Event::MouseButtonReleased)
	{
		m_buttons[event.mouseButton.button] = false;
	}
}

bool Input::Pressed(const sf::Mouse::Button button)
{
	return m_prevButtons[button] == false && m_buttons[button] == true;
}

bool Input::Down(const sf::Mouse::Button button)
{
	return m_buttons[button];
}

bool Input::Released(const sf::Mouse::Button button)
{
	return m_prevButtons[button] == true && m_buttons[button] == false;
}

bool Input::Any()
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