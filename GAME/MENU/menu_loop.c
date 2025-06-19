/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 10:40:18 by amblanch          #+#    #+#             */
/*   Updated: 2025/06/19 15:43:28 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDE/graph.h"


void	menu_loop_load_texture(t_all *all)
{
	menu_theme_bg(all);
	menu_all(all);
	menu_settings(all);
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