#pragma once

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>

#include "Types.hpp"

/**
 * @brief read nemesis config files.
 */
class Config final
{
public:
	/**
	 * @brief load a config file.
	 * @param filename the name of the file.
	 * @return true if reading the file was successful, false otherwise.
	 */
	bool LoadFromFile(const std::string &filename);

	/**
	 * @brief save the config to a file.
	 * @param filename the name of the file.
	 * @return true if saving the config was sucessful, false otherwise.
	 */
	bool SaveToFile(const std::string &filename) const;

	/**
	 * @brief set the value of an attribute.
	 * @tparam T the type of the value.
	 * @param attribute the name of the attribute.
	 * @param value the value of the attribute.
	 * @param to_string function to convert the T value to a string (default std::to_string)
	 */
	template<typename T>
	void SetValue(const std::string &attribute, const T &value)
	{
		attributes.at(attribute) = std::to_string(value);
	}

	/**
	 * @brief get a value of an attribute in the config file.
	 * @tparam T the type of the value.
	 * @param attribute the name of the attribute to get the value of.
	 * @return the value of the attribute as type T.
	 */
	template<typename T>
	T GetValue(const std::string &attribute) const
	{
		return T();
	}

private:
	std::unordered_map<std::string, std::string> attributes;
};
