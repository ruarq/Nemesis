#include "Game.hpp"

#include "GameState.hpp"
#include "States/MenuState.hpp"

void Game::Run()
{
	this->CreateWindow();
	this->LoadData();
	isRunning = true;

	/**
	 * initialize systems
	 */
	Audio::Init();
	UI::Init(window);

	/**
	 * initialize state
	 */
	GameState::Ptr currentState(new MenuState());
	currentState->OnEnter();

	/**
	 * main loop
	 */
	while (window.isOpen() && isRunning)
	{
		/**
		 * handle state transitions
		 */
		if (GameState::Ptr nextState = currentState->NextState())
		{
			currentState->OnExit();
			currentState = std::move(nextState);
			currentState->game = this;
			currentState->OnEnter();
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
		window.clear();

		// update state
		currentState->Update();
		
		// render state
		currentState->Render(window);
	
		window.display();
	}

	/**
	 * shutdowns systems
	 */
	Audio::Shutdown();
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
		window.create(sf::VideoMode(800, 600), "Nemesis");
	}

	if (video_cfg.GetValue<bool>("fullscreen"))
	{
		style |= sf::Style::Fullscreen;
	}

	/**
	 * create the window with the config
	 */
	window.create(
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
	window.setIcon(window_icon.getSize().x, window_icon.getSize().y, window_icon.getPixelsPtr());

	/**
	 * load fonts
	 */
	UI::Fonts::Change(Data::Fonts::Path("FreeMono.ttf"));

	/**
	 * load audio files
	 */
	Audio::LoadMusic("happy", Data::Audio::Path("mu_happy.wav"));
	Audio::LoadMusic("horror", Data::Audio::Path("mu_horror.wav"));
}

void Game::HandleEvents()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::Closed:
				window.close();
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