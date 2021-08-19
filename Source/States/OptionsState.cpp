#include "OptionsState.hpp"

#include "MenuState.hpp"

void OptionsState::on_enter(GameData &data)
{
	m_music_vol_tb.text = "MUSIC VOL";
	m_music_vol_tb.box = UI::Pos::centered(data, Vec2f(200.0f, 10.0f), Vec2f(-100.0f, -50.0f));
	m_music_vol_tb.font_size = 15.0f;

	m_music_vol_slider.min_value = 0.0f;
	m_music_vol_slider.max_value = 100.0f;
	m_music_vol_slider.set_value(gAudioSystem->get_music_volume());
	m_music_vol_slider.rect = UI::Pos::centered(data, Vec2f(200.0f, 10.0f), Vec2f(0.0f, -40.0f));

	m_sound_vol_tb.text = "SOUND VOL";
	m_sound_vol_tb.box = UI::Pos::centered(data, Vec2f(200.0f, 10.0f), Vec2f(-100.0f, -10.0f));
	m_sound_vol_tb.font_size = 15.0f;

	m_sound_vol_slider.min_value = 0.0f;
	m_sound_vol_slider.max_value = 100.0f;
	m_sound_vol_slider.rect = UI::Pos::centered(data, Vec2f(200.0f, 10.0f));

	m_back_btn.text = "BACK";
	m_back_btn.text_align = UI::TextAlign::centered;
	m_back_btn.box = UI::Pos::centered(data, Vec2f(200.0f, 50.0f), Vec2f(0.0f, 40.0f));
}

void OptionsState::update(GameData &data)
{
	m_music_vol_slider.update(data);
	m_sound_vol_slider.update(data);

	gAudioSystem->set_music_volume(m_music_vol_slider.value());

	if (m_back_btn.is_hovered(data))
	{
		m_back_btn.draw_box = true;
	}
	else
	{
		m_back_btn.draw_box = false;
	}

	if (m_back_btn.is_pressed(data))
	{
		is_finished = true;
	}
}

void OptionsState::render(GameData &data) const
{
	data.window.draw(m_music_vol_tb);
	data.window.draw(m_music_vol_slider);
	data.window.draw(m_sound_vol_tb);
	data.window.draw(m_sound_vol_slider);
	data.window.draw(m_back_btn);
}