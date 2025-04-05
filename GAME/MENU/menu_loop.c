/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 10:40:18 by amblanch          #+#    #+#             */
/*   Updated: 2025/04/04 14:29:02 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDE/graph.h"

void	menu_loop(t_all *all)
{
	uint16_t		y;
	Uint8			r;
	Uint8			g;
	Uint8			b;
	float			shadow_factor;
	static int		alpha = 0;

	menu_loop_event(all);
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
	SDL_SetTextureAlphaMod(find_texture(all->texture, "title_menu"), alpha);
	SDL_RenderCopy(all->renderer, find_texture(all->texture, "title_menu"), NULL, find_rect(all->rect, "title_menu"));
	SDL_SetTextureAlphaMod(find_texture(all->texture, "play_bar"), alpha);
	SDL_RenderCopy(all->renderer, find_texture(all->texture, "play_bar"), NULL, find_rect(all->rect, "play_bar"));
	SDL_SetTextureAlphaMod(find_texture(all->texture, "settings_bar"), alpha);
	SDL_RenderCopy(all->renderer, find_texture(all->texture, "settings_bar"), NULL, find_rect(all->rect, "settings_bar"));
	SDL_SetTextureAlphaMod(find_texture(all->texture, "save_bar"), alpha);
	SDL_RenderCopy(all->renderer, find_texture(all->texture, "save_bar"), NULL, find_rect(all->rect, "save_bar"));
	SDL_SetTextureAlphaMod(find_texture(all->texture, "exit_bar"), alpha);
	SDL_RenderCopy(all->renderer, find_texture(all->texture, "exit_bar"), NULL, find_rect(all->rect, "exit_bar"));
	SDL_SetTextureAlphaMod(find_texture(all->texture, "text_play"), alpha);
	SDL_RenderCopy(all->renderer, find_texture(all->texture, "text_play"), NULL, find_rect(all->rect, "text_play"));
	SDL_SetTextureAlphaMod(find_texture(all->texture, "text_settings"), alpha);
	SDL_RenderCopy(all->renderer, find_texture(all->texture, "text_settings"), NULL, find_rect(all->rect, "text_settings"));
	SDL_SetTextureAlphaMod(find_texture(all->texture, "text_save"), alpha);
	SDL_RenderCopy(all->renderer, find_texture(all->texture, "text_save"), NULL, find_rect(all->rect, "text_save"));
	SDL_SetTextureAlphaMod(find_texture(all->texture, "text_exit"), alpha);
	SDL_RenderCopy(all->renderer, find_texture(all->texture, "text_exit"), NULL, find_rect(all->rect, "text_exit"));
	if (alpha < 255)
		alpha += 1;
}