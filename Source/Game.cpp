#include "Game.hpp"

void Game::Run()
{
	this->CreateWindow();
	this->LoadData();

	data.states.front()->OnEnter(data);

	while (data.window.isOpen())
	{
		if (data.states.front()->isFinished)
		{
			data.states.front()->OnLeave(data);
			data.states.pop();

			if (data.states.empty())
			{
				break;
			}

			data.states.front()->OnEnter(data);
		}

		Input::Update();
		Time::Update();

		this->HandleEvents();
		
		data.window.clear();
		data.states.front()->Update(data);
		data.states.front()->Render(data);
		data.window.display();
	}
}

void Game::CreateWindow()
{
	const std::string filename = Data::Config::Path("Video.cfg");
	Config video_cfg;
	u32 style = sf::Style::Close;

	if (!video_cfg.LoadFromFile(filename))
	{
		std::cout << "[Game] => Couldn't load \"" << filename << "\" : creating window with default parameters.\n";
		data.window.create(sf::VideoMode(800, 600), "Nemesis");
	}

	if (video_cfg.GetValue<bool>("fullscreen"))
	{
		style |= sf::Style::Fullscreen;
	}

	data.window.create(
		sf::VideoMode(video_cfg.GetValue<i32>("xres"), video_cfg.GetValue<i32>("yres")),
		"Nemesis",
		style);
}

void Game::LoadData()
{
	UI::Fonts::Change("FreeMono.ttf");

	sf::Image window_icon;
	window_icon.loadFromFile(Data::Images::Path("Icon.png"));
	data.window.setIcon(window_icon.getSize().x, window_icon.getSize().y, window_icon.getPixelsPtr());

	Audio::LoadMusic("happy", Data::Audio::Path("mu_happy.wav"));
	Audio::LoadMusic("horror", Data::Audio::Path("mu_horror.wav"));
}

void Game::HandleEvents()
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
				Input::HandleKeyEvent(event);
				break;

			case sf::Event::MouseButtonPressed:
			case sf::Event::MouseButtonReleased:
				Input::HandleMouseEvent(event);
				break;

			default:
				// TODO(ruarq): Add dispatch function for other parts of the code to handle events.
				break;
		}
	}
}