/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 10:41:31 by amblanch          #+#    #+#             */
/*   Updated: 2025/04/04 14:26:59 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDE/graph.h"

void	menu_loop_event(t_all *all)
{
	int mouse = 0;
	int	mouse_x = 0;
	int mouse_y = 0;
	SDL_Event	event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			all->status = STOP;
		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_ESCAPE)
				all->status = STOP;
		}
		if (event.type == SDL_MOUSEBUTTONDOWN)
		{
            if (event.button.button == SDL_BUTTON_LEFT)
			{
                if (!mouse) 
				{
						
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
		mouse_x = event.button.x;
		mouse_y = event.button.y;
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