/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 10:41:31 by amblanch          #+#    #+#             */
/*   Updated: 2025/06/18 16:29:21 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDE/graph.h"

void	menu_loop_event(t_all *all)
{
	int mouse = 0;
	int	mouse_x = 0;
	int mouse_y = 0;
	int width;
    int height;
	SDL_Event	event;

	while (SDL_PollEvent(&event))
	{
		mouse_x = event.button.x;
		mouse_y = event.button.y;
		//if (event.type == SDL_QUIT)
		//	all->status = STOP;
		if (isButtonClicked(*find_rect(all->rect, "settings_theme"), mouse_x, mouse_y))
			all->btn_menu.settings_btn = 1;
		else if (isButtonClicked(*find_rect(all->rect, "theme_dark"), mouse_x, mouse_y))
			all->btn_menu.settings_btn = 2;
		else if (isButtonClicked(*find_rect(all->rect, "theme_default"), mouse_x, mouse_y))
			all->btn_menu.settings_btn = 3;
		else if (isButtonClicked(*find_rect(all->rect, "theme_troll_btn"), mouse_x, mouse_y))
			all->btn_menu.settings_btn = 4;
		else if (isButtonClicked(*find_rect(all->rect, "theme_dog_btn"), mouse_x, mouse_y))
			all->btn_menu.settings_btn = 5;
		else if (isButtonClicked(*find_rect(all->rect, "theme_sky_btn"), mouse_x, mouse_y))
			all->btn_menu.settings_btn = 6;
		else
			all->btn_menu.settings_btn = 0;
		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_ESCAPE && all->menu == NONE)
				all->status = STOP;
			if (event.key.keysym.sym == SDLK_ESCAPE && all->menu == SETTINGS_BTN)
			{
				all->menu_theme = 0;
				all->menu  = NONE;
			}
			if (event.key.keysym.sym == SDLK_ESCAPE && all->menu == SAVE_BTN)
				all->menu = NONE;
		}
		if (event.type == SDL_WINDOWEVENT)
		{
        	if (event.window.event == SDL_WINDOWEVENT_RESIZED)
			{
            	width = event.window.data1;
            	height = event.window.data2;
				SDL_GetWindowSize(all->window, &width, &height);
				new_size_texture(all, width, height);
				menu_loop_load_texture(all);
			}
        }
		if (event.type == SDL_MOUSEBUTTONDOWN)
		{
            if (event.button.button == SDL_BUTTON_LEFT)
			{
                if (!mouse) 
				{
					if (all->menu == NONE)
					{
						if (isButtonClicked(*find_rect(all->rect, "text_play"), mouse_x, mouse_y))
						{
							Mix_PlayChannel(-1, all->click, 0);
							all->render = EDGE_SCREEN;
							init_rect_for_texture_level1(all);
							init_texture_level1(all);
							SDL_GetWindowSize(all->window, &width, &height);
							new_size_texture(all, width, height);
						}
						if (isButtonClicked(*find_rect(all->rect, "text_settings"), mouse_x, mouse_y))
						{
							Mix_PlayChannel(-1, all->click, 0);
							all->menu = SETTINGS_BTN;
						}
						if (isButtonClicked(*find_rect(all->rect, "text_save"), mouse_x, mouse_y))
						{
							Mix_PlayChannel(-1, all->click, 0);
							all->menu = SAVE_BTN;
						}
						if (isButtonClicked(*find_rect(all->rect, "text_exit"), mouse_x, mouse_y))
						{
							Mix_PlayChannel(-1, all->click, 0);
							all->status = STOP;
						}
					}
				}
				if (all->menu == SETTINGS_BTN && all->menu_theme == 0)
				{
					if (isButtonClicked(*find_rect(all->rect, "settings_theme"), mouse_x, mouse_y))
					{
						all->menu_theme = 1;
						all->btn_menu.settings_btn = 1;
					}
				}
				if (all->menu_theme == 1 && all->menu == SETTINGS_BTN)
				{
					if (isButtonClicked(*find_rect(all->rect, "theme_default"), mouse_x, mouse_y))
						all->param_theme = 0;
					if (isButtonClicked(*find_rect(all->rect, "theme_dark"), mouse_x, mouse_y))
						all->param_theme = 1;
					if (isButtonClicked(*find_rect(all->rect, "theme_sky_btn"), mouse_x, mouse_y))
						all->param_theme = 2;
					if (isButtonClicked(*find_rect(all->rect, "theme_troll_btn"), mouse_x, mouse_y))
						all->param_theme = 3;
					if (isButtonClicked(*find_rect(all->rect, "theme_dog_btn"), mouse_x, mouse_y))
						all->param_theme = 4;
				}
			}
		}
		else if (event.type == SDL_MOUSEBUTTONUP)
		{
            if (event.button.button == SDL_BUTTON_LEFT)
			{
               mouse = 0;
    	    }
		}
		if (isButtonClicked(*find_rect(all->rect, "text_play"), mouse_x, mouse_y))
			all->status_btn = 1;
		else if (isButtonClicked(*find_rect(all->rect, "text_settings"), mouse_x, mouse_y))
			all->status_btn = 2;
		else if (isButtonClicked(*find_rect(all->rect, "text_save"), mouse_x, mouse_y))
			all->status_btn = 3;
		else if (isButtonClicked(*find_rect(all->rect, "text_exit"), mouse_x, mouse_y))
			all->status_btn = 4;
		else
			all->status_btn = 0;
	}
}