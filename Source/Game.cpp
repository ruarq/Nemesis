#include "Game.hpp"

void Game::Run()
{
	this->CreateWindow();
	this->LoadData();

	data.states.front()->OnEnter(data);

	while (data.window.isOpen())
	{
		/**
		 * handle state transitions
		 */
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

		/**
		 * update systems
		 */
		Input::Update();
		Time::Update();

		/**
		 * handle events
		 */
		this->HandleEvents();
		
		/**
		 * draw & update
		 */
		data.window.clear();

		// update state
		data.states.front()->Update(data);
		
		// render state
		data.states.front()->Render(data);
	
		data.window.display();
	}
}

void Game::CreateWindow()
{
	/**
	 * config file setup
	 */
	const std::string filename = Data::Config::Path("Video.cfg");
	Config video_cfg;
	u32 style = sf::Style::Close;

	/**
	 * try to read the values from the config file
	 */
	if (!video_cfg.LoadFromFile(filename))
	{
		std::cout << "[Game] => Couldn't load \"" << filename << "\" : creating window with default parameters.\n";
		data.window.create(sf::VideoMode(800, 600), "Nemesis");
	}

	if (video_cfg.GetValue<bool>("fullscreen"))
	{
		style |= sf::Style::Fullscreen;
	}

	/**
	 * create the window with the config
	 */
	data.window.create(
		sf::VideoMode(video_cfg.GetValue<i32>("xres"), video_cfg.GetValue<i32>("yres")),
		"Nemesis",
		style);
}

void Game::LoadData()
{
	/**
	 * load nemesis's icon
	 */
	sf::Image window_icon;
	window_icon.loadFromFile(Data::Images::Path("Icon.png"));
	data.window.setIcon(window_icon.getSize().x, window_icon.getSize().y, window_icon.getPixelsPtr());

	/**
	 * load fonts
	 */
	UI::Fonts::Change("FreeMono.ttf");

	/**
	 * load audio files
	 */
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