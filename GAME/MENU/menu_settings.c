/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_settings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:37:26 by amblanch          #+#    #+#             */
/*   Updated: 2025/06/19 15:44:11 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDE/graph.h"

void    menu_settings(t_all *all)
{
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
}
