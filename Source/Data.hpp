#pragma once

#include <string>

#define _NMS_ADD_SUBDIR(Parentdir, Subdir) \
	struct Subdir final { \
		static std::string path(const std::string &local = "") { \
			return Parentdir::path(#Subdir"/"); \
		} \
	}

/**
 * @brief Data directory
 */
struct Data final
{
	static std::string path(const std::string &local = "")
	{
		return std::string("Data/") + local;
	}

	_NMS_ADD_SUBDIR(Data, Audio);
	_NMS_ADD_SUBDIR(Data, Config);
	_NMS_ADD_SUBDIR(Data, Fonts);
	_NMS_ADD_SUBDIR(Data, Images);
	_NMS_ADD_SUBDIR(Data, Other);
	_NMS_ADD_SUBDIR(Data, Rooms);
};