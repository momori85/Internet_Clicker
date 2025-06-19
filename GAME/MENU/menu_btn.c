/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_btn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:28:36 by amblanch          #+#    #+#             */
/*   Updated: 2025/06/19 15:44:14 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDE/graph.h"

int    animation_btn(t_all *all, int status_btn, char *name_rect)
{
    if (all->status_btn_down == status_btn)
	{
		if (all->count_time_btn >= 10)
		{
			all->count_time_btn = 0;
			all->status_btn_down = 0;
			SDL_SetTextureAlphaMod(find_texture(all->texture, "menu_bar"), all->alpha);
			SDL_RenderCopy(all->renderer, find_texture(all->texture, "menu_bar"), NULL, find_rect(all->rect, name_rect));
            return (1);
		}
		else
		{
			all->count_time_btn++;
			SDL_SetTextureAlphaMod(find_texture(all->texture, "menu_bar_down"), all->alpha);
			SDL_RenderCopy(all->renderer, find_texture(all->texture, "menu_bar_down"), NULL, find_rect(all->rect, name_rect));
		}
	}
	else
	{
		SDL_SetTextureAlphaMod(find_texture(all->texture, "menu_bar"), all->alpha);
		SDL_RenderCopy(all->renderer, find_texture(all->texture, "menu_bar"), NULL, find_rect(all->rect, name_rect));
	}
    return (0);
}
