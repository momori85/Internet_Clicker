/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_theme_bg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:41:39 by amblanch          #+#    #+#             */
/*   Updated: 2025/06/19 15:44:04 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDE/graph.h"

void    menu_theme_bg(t_all *all)
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
}
