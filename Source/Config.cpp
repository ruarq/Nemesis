#include "Config.hpp"

bool Config::load_from_file(const std::string &filename)
{
	std::ifstream config_file(filename);
	std::string attrib, value;

	if (!config_file.is_open())
	{
		return false;
	}

	while (!config_file.eof())
	{
		config_file >> attrib >> value;
		m_attributes.emplace(attrib, value);
	}

	return true;
}

bool Config::save_to_file(const std::string &filename) const
{
	std::ofstream config_file(filename);
	
	if (!config_file.is_open())
	{
		return false;
	}

	for (auto &pair : m_attributes)
	{
		config_file << pair.first << " " << pair.second << "\n";
	}

	return true;
}

template<>
void Config::set_value(const std::string &attribute, const std::string &value)
{
	m_attributes.at(attribute) = value;
}

template<>
i32 Config::get_value(const std::string &attribute) const
{
	return std::stoi(m_attributes.at(attribute));
}

template<>
bool Config::get_value(const std::string &attribute) const
{
	return this->get_value<i32>(attribute);
}

template<>
f32 Config::get_value(const std::string &attribute) const
{
	return std::stof(m_attributes.at(attribute));
}
