#include "Game.hpp"

void Game::run()
{
	this->create_window();
	this->load_data();

	data.state_queue.front()->on_enter(data);

	while (data.window.isOpen())
	{
		if (data.state_queue.front()->is_finished)
		{
			data.state_queue.front()->on_leave(data);
			data.state_queue.pop();

			if (data.state_queue.empty())
			{
				break;
			}

			data.state_queue.front()->on_enter(data);
		}

		gInput->update();
		gTime->update();

		this->handle_events();
		
		data.window.clear();
		data.state_queue.front()->update(data);
		data.state_queue.front()->render(data);
		data.window.display();
	}
}

void Game::create_window()
{
	const std::string filename = Data::Config::path("Video.cfg");
	Config video_cfg;
	u32 style = sf::Style::Close;

	if (!video_cfg.load_from_file(filename))
	{
		std::cout << "[Game] => Couldn't load \"" << filename << "\" : creating window with default parameters.\n";
		data.window.create(sf::VideoMode(800, 600), "Nemesis");
	}

	if (video_cfg.get_value<bool>("fullscreen"))
	{
		style |= sf::Style::Fullscreen;
	}

	data.window.create(
		sf::VideoMode(video_cfg.get_value<i32>("xres"), video_cfg.get_value<i32>("yres")),
		"Nemesis",
		style);
}

void Game::load_data()
{
	UI::Fonts::change("FreeMono.ttf");

	sf::Image window_icon;
	window_icon.loadFromFile(Data::Images::path("Icon.png"));
	data.window.setIcon(window_icon.getSize().x, window_icon.getSize().y, window_icon.getPixelsPtr());

	gAudioSystem->load_music("happy", Data::Audio::path("mu_happy.wav"));
	gAudioSystem->load_music("horror", Data::Audio::path("mu_horror.wav"));

	if (!Room::ground_texture.loadFromFile(Data::Images::path("Ground.png")))
	{
		std::cout << "[Game] => Couldn't load \"" << Data::Images::path("Ground.png") << "\n";
	}
	
	if (!Room::wall_texture.loadFromFile(Data::Images::path("Wall.png")))
	{
		std::cout << "[Game] => Couldn't load \"" << Data::Images::path("Wall.png") << "\n";
	}
}

void Game::handle_events()
{
	sf::Event event;
	while (data.window.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::Closed:
				data.window.close();
				break;

			case sf::Event::KeyPressed:
			case sf::Event::KeyReleased:
				gInput->handle_key_event(event);
				break;

			case sf::Event::MouseButtonPressed:
			case sf::Event::MouseButtonReleased:
				gInput->handle_mouse_event(event);
				break;

			default:
				// TODO(ruarq): Add dispatch function for other parts of the code to handle events.
				break;
		}
	}
}