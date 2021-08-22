#include "Config.hpp"

bool Config::LoadFromFile(const std::string &filename)
{
	std::ifstream configFile(filename);
	std::string attrib, value;

	if (!configFile.is_open())
	{
		std::cout << "[Config] => Couldn't load \"" << filename << "\"\n";
		return false;
	}

	while (!configFile.eof())
	{
		configFile >> attrib >> value;
		m_attributes.emplace(attrib, value);
	}

	return true;
}

bool Config::SaveToFile(const std::string &filename) const
{
	std::ofstream configFile(filename);
	
	if (!configFile.is_open())
	{
		std::cout << "[Config] => Couldn't save \"" << filename << "\"\n";
		return false;
	}

	for (auto &pair : m_attributes)
	{
		configFile << pair.first << " " << pair.second << "\n";
	}

	return true;
}

template<>
void Config::SetValue(const std::string &attribute, const std::string &value)
{
	m_attributes.at(attribute) = value;
}

template<>
i32 Config::GetValue(const std::string &attribute) const
{
	return std::stoi(m_attributes.at(attribute));
}

template<>
bool Config::GetValue(const std::string &attribute) const
{
	return this->GetValue<i32>(attribute);
}

template<>
f32 Config::GetValue(const std::string &attribute) const
{
	return std::stof(m_attributes.at(attribute));
}
