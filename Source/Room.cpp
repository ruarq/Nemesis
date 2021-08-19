#include "Room.hpp"

bool Room::load_from_file(const std::string &filename)
{
	std::ifstream file(Data::Rooms::path(filename));
	std::string line;
	Vec2i pos;

	if (!file.is_open())
	{
		std::cout << "[Room] => Couldn't load \"" << filename << "\"\n";
		return false;
	}

	while (std::getline(file, line))
	{
		if (line.size() != width || pos.y >= height)
		{
			std::cout << "[Room] => Invalid dimensions in file \"" << filename << "\"\n";
			return false;	
		}

		pos.x = 0;
		for (const char c : line)
		{
			if (c == '#')
			{
				this->set_tile(pos, Tile(Tile::Wall));
			}
			else if (c == '.')
			{
				this->set_tile(pos, Tile(Tile::Ground));
			}
			else if (c == ' ')
			{
				this->set_tile(pos, Tile(Tile::Empty));
			}
			else
			{
				std::cout << "[Room] => Unexpected character in file \"" << filename << "\"\n";
				return false;
			}

			pos.x++;
		}
		
		pos.y++;
	}

	return true;
}

void Room::set_tile(const Vec2i &pos, const Tile &tile)
{
	this->get_tile(pos) = tile;
}

Tile& Room::get_tile(const Vec2i &pos)
{
	return tiles.at(pos.y * width + pos.y);
}

const Tile& Room::get_tile(const Vec2i &pos) const
{
	return tiles.at(pos.y * width + pos.x);
}