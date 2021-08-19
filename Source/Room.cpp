#include "Room.hpp"

u32 Room::tile_width = 32;
u32 Room::tile_height = 32;
sf::Texture Room::ground_texture;
sf::Texture Room::wall_texture;

bool Room::load_from_file(const std::string &filename)
{
	std::ifstream file(Data::Rooms::path(filename));
	std::string line;
	Vec2i pos;

	if (!file.is_open())
	{
		std::cout << "[Room] => Couldn't load \"" << Data::Rooms::path(filename) << "\"\n";
		return false;
	}

	while (std::getline(file, line))
	{
		if (line.size() != width || pos.y >= height)
		{
			std::cout << "[Room] => Invalid dimensions in file \"" << Data::Rooms::path(filename) << "\"\n";
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
				std::cout << "[Room] => Unexpected character in file \"" << Data::Rooms::path(filename) << "\"\n";
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
	return tiles.at(pos.y * width + pos.x);
}

const Tile& Room::get_tile(const Vec2i &pos) const
{
	return tiles.at(pos.y * width + pos.x);
}

void Room::render(sf::RenderWindow &window) const
{
	sf::Sprite sprite;

	for (u32 y = 0; y < height; y++)
	{
		for (u32 x = 0; x < width; x++)
		{
			sprite.setPosition(pos.x * tile_width * width + x * tile_width, pos.y * tile_height * height + y * tile_height);
			if (this->get_tile(Vec2f(x, y)).type == Tile::Ground)
			{
				sprite.setTexture(ground_texture);
				sprite.setScale(Vec2f(f32(tile_width) / f32(ground_texture.getSize().x), f32(tile_height) / f32(ground_texture.getSize().y)));
				window.draw(sprite);
			}
			else if (this->get_tile(Vec2f(x, y)).type == Tile::Wall)
			{
				sprite.setTexture(wall_texture);
				sprite.setScale(Vec2f(f32(tile_width) / f32(wall_texture.getSize().x), f32(tile_height) / f32(wall_texture.getSize().y)));
				window.draw(sprite);
			}
		}
	}
}