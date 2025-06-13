/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaury <amaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 10:40:18 by amblanch          #+#    #+#             */
/*   Updated: 2025/06/13 21:51:34 by amaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDE/graph.h"

void	menu_loop_load_texture(t_all *all)
{
	uint16_t		y;
	Uint8			r;
	Uint8			g;
	Uint8			b;
	float			shadow_factor;
	
	SDL_RenderClear(all->renderer);
	Uint8 final_r = 0x85;
	Uint8 final_g = 0x67;
	Uint8 final_b = 0xF7;

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
	if (all->menu == NONE)
	{
		SDL_SetTextureAlphaMod(find_texture(all->texture, "title_menu"), all->alpha);
		SDL_RenderCopy(all->renderer, find_texture(all->texture, "title_menu"), NULL, find_rect(all->rect, "title_menu"));
		SDL_SetTextureAlphaMod(find_texture(all->texture, "play_bar"), all->alpha);
		SDL_RenderCopy(all->renderer, find_texture(all->texture, "play_bar"), NULL, find_rect(all->rect, "play_bar"));
		SDL_SetTextureAlphaMod(find_texture(all->texture, "settings_bar"), all->alpha);
		SDL_RenderCopy(all->renderer, find_texture(all->texture, "settings_bar"), NULL, find_rect(all->rect, "settings_bar"));
		SDL_SetTextureAlphaMod(find_texture(all->texture, "save_bar"), all->alpha);
		SDL_RenderCopy(all->renderer, find_texture(all->texture, "save_bar"), NULL, find_rect(all->rect, "save_bar"));
		SDL_SetTextureAlphaMod(find_texture(all->texture, "exit_bar"), all->alpha);
		SDL_RenderCopy(all->renderer, find_texture(all->texture, "exit_bar"), NULL, find_rect(all->rect, "exit_bar"));
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
		;
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