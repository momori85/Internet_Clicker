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
	menu_loop_event(all);
	SDL_RenderCopy(all->renderer, find_texture(all->texture, "title_menu"), NULL, find_rect(all->rect, "title_menu"));
	SDL_RenderCopy(all->renderer, find_texture(all->texture, "play_bar"), NULL, find_rect(all->rect, "play_bar"));
	SDL_RenderCopy(all->renderer, find_texture(all->texture, "settings_bar"), NULL, find_rect(all->rect, "settings_bar"));
	SDL_RenderCopy(all->renderer, find_texture(all->texture, "save_bar"), NULL, find_rect(all->rect, "save_bar"));
	SDL_RenderCopy(all->renderer, find_texture(all->texture, "exit_bar"), NULL, find_rect(all->rect, "exit_bar"));
}