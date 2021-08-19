#pragma once

#include <string>

/**
 * @brief Data directory
 */
struct Data final
{
	static std::string path(const std::string &local = "")
	{
		return std::string("Data/") + local;
	}

	/**
	 * @brief Data/Audio directory
	 */
	struct Audio final
	{
		static std::string path(const std::string &local = "")
		{
			return Data::path("Audio/") + local;
		}
	};

	/**
	 * @brief Data/Config directory
	 */
	struct Config final
	{
		static std::string path(const std::string &local = "")
		{
			return Data::path("Config/") + local;
		}
	};

	/**
	 * @brief Data/Fonts directory
	 */
	struct Fonts final
	{
		static std::string path(const std::string &local = "")
		{
			return Data::path("Fonts/") + local;
		}
	};

	/**
	 * @brief Data/Other directory
	 */
	struct Other final
	{
		static std::string path(const std::string &local = "")
		{
			return Data::path("Other/") + local;
		}
	};

	/**
	 * @brief Data/Rooms directory
	 */
	struct Rooms final
	{
		static std::string path(const std::string &local = "")
		{
			return Data::path("Rooms/") + local;
		}
	};
};