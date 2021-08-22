#include "Input.hpp"

std::array<bool, sf::Keyboard::KeyCount> Input::keys;
std::array<bool, sf::Keyboard::KeyCount> Input::prevKeys;

std::array<bool, sf::Mouse::ButtonCount> Input::buttons;
std::array<bool, sf::Mouse::ButtonCount> Input::prevButtons;

void Input::Update()
{
	prevKeys = keys;
	prevButtons = buttons;
}

void Input::HandleKeyEvent(const sf::Event &event)
{
	prevKeys = keys;

	if (event.type == sf::Event::KeyPressed)
	{
		keys[event.key.code] = true;
	}
	else if (event.type == sf::Event::KeyReleased)
	{
		keys[event.key.code] = false;
	}
}

bool Input::Pressed(const sf::Keyboard::Key key)
{
	return prevKeys[key] == false && keys[key] == true;
}

bool Input::Down(const sf::Keyboard::Key key)
{
	return keys[key] == true;
}

bool Input::Released(const sf::Keyboard::Key key)
{
	return prevKeys[key] == true && keys[key] == false;
}

void Input::HandleMouseEvent(const sf::Event &event)
{
	prevButtons = buttons;

	if (event.type == sf::Event::MouseButtonPressed)
	{
		buttons[event.mouseButton.button] = true;
	}
	else if (event.type == sf::Event::MouseButtonReleased)
	{
		buttons[event.mouseButton.button] = false;
	}
}

bool Input::Pressed(const sf::Mouse::Button button)
{
	return prevButtons[button] == false && buttons[button] == true;
}

bool Input::Down(const sf::Mouse::Button button)
{
	return buttons[button];
}

bool Input::Released(const sf::Mouse::Button button)
{
	return prevButtons[button] == true && buttons[button] == false;
}

bool Input::Any()
{
	for (const bool key : keys)
	{
		if (key)
		{
			return true;
		}
	}

	for (const bool button : buttons)
	{
		if (button)
		{
			return true;
		}
	}

	return false;
}