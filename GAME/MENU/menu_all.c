/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:39:40 by amblanch          #+#    #+#             */
/*   Updated: 2025/06/19 15:44:08 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDE/graph.h"

void    menu_all(t_all *all)
{
    if (all->menu == NONE)
	{
		SDL_Rect	*tmp_pos;
		tmp_pos = find_rect(all->rect, "cochon");
		if (tmp_pos->y <= 2000)
			SDL_RenderCopy(all->renderer, find_texture(all->texture, "cochon"), NULL, find_rect(all->rect, "cochon"));
		SDL_SetTextureAlphaMod(find_texture(all->texture, "title_menu"), all->alpha);
		SDL_RenderCopy(all->renderer, find_texture(all->texture, "title_menu"), NULL, find_rect(all->rect, "title_menu"));

		if (animation_btn(all, 1, "play_bar") == 1)
			all->render = TRANSI;
		if (animation_btn(all, 2, "settings_bar") == 1)
			all->menu = SETTINGS_BTN;
		if (animation_btn(all, 3, "save_bar") == 1)
			all->menu = SAVE_BTN;
		if (animation_btn(all, 4, "exit_bar") == 1)
			all->status = STOP;
	
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
}
