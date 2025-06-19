/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 10:40:18 by amblanch          #+#    #+#             */
/*   Updated: 2025/06/19 15:17:20 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDE/graph.h"


void	menu_loop_load_texture(t_all *all)
{
	uint16_t		y;
	Uint8			r;
	Uint8			g;
	Uint8			b;
	Uint8 final_r;
	Uint8 final_g;
	Uint8 final_b;
	float			shadow_factor;
	
	SDL_RenderClear(all->renderer);
	if (all->param_theme == 0)
	{
		final_r = THEME_DEFAUT_R;
		final_g = THEME_DEFAUT_G;
		final_b = THEME_DEFAUT_B;
	}
	else if (all->param_theme == 1)
	{
		final_r = THEME_DARK_R;
		final_g = THEME_DARK_G;
		final_b = THEME_DARK_B;
	}
	else if (all->param_theme == 2)
	{
		SDL_RenderCopy(all->renderer, find_texture(all->texture, "theme_sky"), NULL, find_rect(all->rect, "theme_dog"));
	}
	else if (all->param_theme == 3)
	{
		SDL_RenderCopy(all->renderer, find_texture(all->texture, "theme_troll"), NULL, find_rect(all->rect, "theme_troll"));
	}
	else if (all->param_theme == 4)
	{
		SDL_RenderCopy(all->renderer, find_texture(all->texture, "theme_dog"), NULL, find_rect(all->rect, "theme_dog"));
	}
	
	if (all->param_theme <= 1)
	{
		y = 0;
		while (y < SCREEN_HEIGHT)
		{
			r = (Uint8)(final_r);
			g = (Uint8)(final_g);
			b = (Uint8)(final_b);
			
			shadow_factor = (float)y / (SCREEN_HEIGHT - 300);
			shadow_factor = shadow_factor * shadow_factor * 0.5f;
			
			r = (Uint8)(r * (1.0f - shadow_factor));
			g = (Uint8)(g * (1.0f - shadow_factor));
			b = (Uint8)(b * (1.0f - shadow_factor));
	
			SDL_SetRenderDrawColor(all->renderer, r, g, b, 255);
			SDL_RenderDrawLine(all->renderer, 0, y, SCREEN_WIDTH, y);
			y++;
		}
	}
	if (all->menu == NONE)
	{
		SDL_Rect	*tmp_pos;
		tmp_pos = find_rect(all->rect, "cochon");
		if (tmp_pos->y <= 2000)
			SDL_RenderCopy(all->renderer, find_texture(all->texture, "cochon"), NULL, find_rect(all->rect, "cochon"));
		SDL_SetTextureAlphaMod(find_texture(all->texture, "title_menu"), all->alpha);
		SDL_RenderCopy(all->renderer, find_texture(all->texture, "title_menu"), NULL, find_rect(all->rect, "title_menu"));

		if (all->status_btn_down == 1)
		{
			if (all->count_time_btn >= 10)
			{
				all->render = TRANSI;
				all->count_time_btn = 0;
				all->status_btn_down = 0;
				SDL_SetTextureAlphaMod(find_texture(all->texture, "menu_bar"), all->alpha);
				SDL_RenderCopy(all->renderer, find_texture(all->texture, "menu_bar"), NULL, find_rect(all->rect, "play_bar"));
			}
			else
			{
				all->count_time_btn++;
				SDL_SetTextureAlphaMod(find_texture(all->texture, "menu_bar_down"), all->alpha);
				SDL_RenderCopy(all->renderer, find_texture(all->texture, "menu_bar_down"), NULL, find_rect(all->rect, "play_bar"));
			}
		}
		else
		{
			SDL_SetTextureAlphaMod(find_texture(all->texture, "menu_bar"), all->alpha);
			SDL_RenderCopy(all->renderer, find_texture(all->texture, "menu_bar"), NULL, find_rect(all->rect, "play_bar"));
		}
		
		if (all->status_btn_down == 2)
		{
			if (all->count_time_btn >= 10)
			{
				all->menu = SETTINGS_BTN;
				all->count_time_btn = 0;
				all->status_btn_down = 0;
				SDL_SetTextureAlphaMod(find_texture(all->texture, "menu_bar"), all->alpha);
				SDL_RenderCopy(all->renderer, find_texture(all->texture, "menu_bar"), NULL, find_rect(all->rect, "settings_bar"));
			}
			else
			{
				all->count_time_btn++;
				SDL_SetTextureAlphaMod(find_texture(all->texture, "menu_bar_down"), all->alpha);
				SDL_RenderCopy(all->renderer, find_texture(all->texture, "menu_bar_down"), NULL, find_rect(all->rect, "settings_bar"));
			}
		}
		else
		{
			SDL_SetTextureAlphaMod(find_texture(all->texture, "menu_bar"), all->alpha);
			SDL_RenderCopy(all->renderer, find_texture(all->texture, "menu_bar"), NULL, find_rect(all->rect, "settings_bar"));
		}

		if (all->status_btn_down == 3)
		{
			if (all->count_time_btn >= 10)
			{
				all->menu = SAVE_BTN;
				all->count_time_btn = 0;
				all->status_btn_down = 0;
				SDL_SetTextureAlphaMod(find_texture(all->texture, "menu_bar"), all->alpha);
				SDL_RenderCopy(all->renderer, find_texture(all->texture, "menu_bar"), NULL, find_rect(all->rect, "save_bar"));
			}
			else
			{
				all->count_time_btn++;
				SDL_SetTextureAlphaMod(find_texture(all->texture, "menu_bar_down"), all->alpha);
				SDL_RenderCopy(all->renderer, find_texture(all->texture, "menu_bar_down"), NULL, find_rect(all->rect, "save_bar"));
			}
		}
		else
		{
			SDL_SetTextureAlphaMod(find_texture(all->texture, "menu_bar"), all->alpha);
			SDL_RenderCopy(all->renderer, find_texture(all->texture, "menu_bar"), NULL, find_rect(all->rect, "save_bar"));
		}

		if (all->status_btn_down == 4)
		{
			if (all->count_time_btn >= 10)
			{
				all->status = STOP;
				all->count_time_btn = 0;
				all->status_btn_down = 0;
				SDL_SetTextureAlphaMod(find_texture(all->texture, "menu_bar"), all->alpha);
				SDL_RenderCopy(all->renderer, find_texture(all->texture, "menu_bar"), NULL, find_rect(all->rect, "exit_bar"));
			}
			else
			{
				all->count_time_btn++;
				SDL_SetTextureAlphaMod(find_texture(all->texture, "menu_bar_down"), all->alpha);
				SDL_RenderCopy(all->renderer, find_texture(all->texture, "menu_bar_down"), NULL, find_rect(all->rect, "exit_bar"));
			}
		}
		else
		{
			SDL_SetTextureAlphaMod(find_texture(all->texture, "menu_bar"), all->alpha);
			SDL_RenderCopy(all->renderer, find_texture(all->texture, "menu_bar"), NULL, find_rect(all->rect, "exit_bar"));
		}
	
		if (all->status_btn == 1)
		{
			SDL_SetTextureAlphaMod(find_texture(all->texture, "text_play_white"), all->alpha);
			SDL_RenderCopy(all->renderer, find_texture(all->texture, "text_play_white"), NULL, find_rect(all->rect, "text_play"));
		}
		else
		{
			SDL_SetTextureAlphaMod(find_texture(all->texture, "text_play"), all->alpha);
			SDL_RenderCopy(all->renderer, find_texture(all->texture, "text_play"), NULL, find_rect(all->rect, "text_play"));
		}
		if (all->status_btn == 2)
		{
			SDL_SetTextureAlphaMod(find_texture(all->texture, "text_settings_white"), all->alpha);
			SDL_RenderCopy(all->renderer, find_texture(all->texture, "text_settings_white"), NULL, find_rect(all->rect, "text_settings"));
		}
		else
		{
			SDL_SetTextureAlphaMod(find_texture(all->texture, "text_settings"), all->alpha);
			SDL_RenderCopy(all->renderer, find_texture(all->texture, "text_settings"), NULL, find_rect(all->rect, "text_settings"));
		}
		if (all->status_btn == 3)
		{
			SDL_SetTextureAlphaMod(find_texture(all->texture, "text_save_white"), all->alpha);
			SDL_RenderCopy(all->renderer, find_texture(all->texture, "text_save_white"), NULL, find_rect(all->rect, "text_save"));
		}
		else
		{
			SDL_SetTextureAlphaMod(find_texture(all->texture, "text_save"), all->alpha);
			SDL_RenderCopy(all->renderer, find_texture(all->texture, "text_save"), NULL, find_rect(all->rect, "text_save"));
		}
		if (all->status_btn == 4)
		{
			SDL_SetTextureAlphaMod(find_texture(all->texture, "text_exit_white"), all->alpha);
			SDL_RenderCopy(all->renderer, find_texture(all->texture, "text_exit_white"), NULL, find_rect(all->rect, "text_exit"));
		}
		else
		{
			SDL_SetTextureAlphaMod(find_texture(all->texture, "text_exit"), all->alpha);
			SDL_RenderCopy(all->renderer, find_texture(all->texture, "text_exit"), NULL, find_rect(all->rect, "text_exit"));
		}
		if (all->alpha < 255)
			all->alpha += 1;
	}
	if (all->menu == SETTINGS_BTN)
	{
		if (all->btn_menu.settings_btn == 1)
			SDL_RenderCopy(all->renderer, find_texture(all->texture, "settings_theme_white"), NULL, find_rect(all->rect, "settings_theme"));
		else
			SDL_RenderCopy(all->renderer, find_texture(all->texture, "settings_theme"), NULL, find_rect(all->rect, "settings_theme"));
		if (all->menu_theme == 1)
		{
			if (all->btn_menu.settings_btn == 2)
				SDL_RenderCopy(all->renderer, find_texture(all->texture, "theme_dark_white"), NULL, find_rect(all->rect, "theme_dark"));
			else
				SDL_RenderCopy(all->renderer, find_texture(all->texture, "theme_dark"), NULL, find_rect(all->rect, "theme_dark"));
			if (all->btn_menu.settings_btn == 3)
				SDL_RenderCopy(all->renderer, find_texture(all->texture, "theme_default_white"), NULL, find_rect(all->rect, "theme_default"));
			else
				SDL_RenderCopy(all->renderer, find_texture(all->texture, "theme_default"), NULL, find_rect(all->rect, "theme_default"));
			if (all->btn_menu.settings_btn == 4)
				SDL_RenderCopy(all->renderer, find_texture(all->texture, "theme_troll_btn_white"), NULL, find_rect(all->rect, "theme_troll_btn"));
			else
				SDL_RenderCopy(all->renderer, find_texture(all->texture, "theme_troll_btn"), NULL, find_rect(all->rect, "theme_troll_btn"));
			if (all->btn_menu.settings_btn == 5)
				SDL_RenderCopy(all->renderer, find_texture(all->texture, "theme_dog_btn_white"), NULL, find_rect(all->rect, "theme_dog_btn"));
			else
				SDL_RenderCopy(all->renderer, find_texture(all->texture, "theme_dog_btn"), NULL, find_rect(all->rect, "theme_dog_btn"));
			if (all->btn_menu.settings_btn == 6)
				SDL_RenderCopy(all->renderer, find_texture(all->texture, "theme_sky_btn_white"), NULL, find_rect(all->rect, "theme_sky_btn"));
			else
				SDL_RenderCopy(all->renderer, find_texture(all->texture, "theme_sky_btn"), NULL, find_rect(all->rect, "theme_sky_btn"));
		}
	}
	if (all->menu == SAVE_BTN)
	{
		;
	}

}

void	menu_loop(t_all *all)
{
	menu_loop_event(all);
	menu_loop_load_texture(all);
}