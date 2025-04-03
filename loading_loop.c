/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:23:33 by amblanch          #+#    #+#             */
/*   Updated: 2025/04/03 15:26:43 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void	loading_loop_event(t_all *all)
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
					mouse_x = event.button.x;
					mouse_y = event.button.y;
					if (all->render != MAIN_SCREEN && isButtonClicked(*find_rect(all->rect, "play"), mouse_x, mouse_y))
						all->button = PLAY_BTN_DOWN;
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
	}
}

static int16_t	ft_update_pos(t_all *all, int offset)
{
	SDL_Rect		*tmp;

	tmp = find_rect(all->rect, "play");
	tmp->y += offset;
	tmp = find_rect(all->rect, "meme");
	tmp->x -= offset;
	tmp->y += offset;
	tmp = find_rect(all->rect, "meme1");
	tmp->x -= offset;
	tmp->y += offset;
	tmp = find_rect(all->rect, "meme2");
	tmp->x += offset;
	tmp = find_rect(all->rect, "meme3");
	tmp->x += offset;
	tmp->y += offset;
	tmp = find_rect(all->rect, "meme4");
	tmp->x -= offset;
	tmp->y -= offset;
	tmp = find_rect(all->rect, "meme5");
	tmp->x += offset;
	tmp->y -= offset;
	tmp = find_rect(all->rect, "meme6");
	tmp->x -= offset;
	tmp->y -= offset;
	tmp = find_rect(all->rect, "cat_left");
	tmp->x -= offset;
	tmp = find_rect(all->rect, "cat_right");
	tmp->x += offset;
	tmp = find_rect(all->rect, "title");
	tmp->y -= offset;
	return (tmp->y);
}

void	load_screen_loop(t_all *all, Uint32 start_time, int offset)
{
	Uint32		frame_duration;

	loading_loop_event(all);
	SDL_RenderClear(all->renderer);
	if (all->button == PLAY_BTN_DOWN && all->render == LOAD_SCREEN)
	{
		if (ft_update_pos(all, offset) <= -1000)
		{
			deleteNode(&all->rect, "title");
			deleteNode(&all->rect, "play");
			deleteNode(&all->rect, "meme");
			deleteNode(&all->rect, "meme1");
			deleteNode(&all->rect, "meme2");
			deleteNode(&all->rect, "meme3");
			deleteNode(&all->rect, "meme4");
			deleteNode(&all->rect, "meme5");
			deleteNode(&all->rect, "meme6");
			deleteNode(&all->rect, "cat_left");
			deleteNode(&all->rect, "cat_right");
			all->render = MAIN_SCREEN;
		}
		if (offset < 10)
			offset++;
		offset += 1;
	}
	process_screen(all, all->render);
	SDL_RenderPresent(all->renderer);
	frame_duration = SDL_GetTicks() - start_time; 
	if (frame_duration < 1000 / 60)
		SDL_Delay((1000 / 60) - frame_duration);
}


void	loading_loop(t_all	*all)
{
	Uint32			start_time = 0;
	int				offset;

	offset = 1;
	while (all->status == RUNNING && all->render != MAIN_SCREEN)
	{
		start_time = SDL_GetTicks();
		switch (all->render)
		{
			case LOAD_SCREEN:
				load_screen_loop(all, start_time, offset);
				break ;
			case MAIN_SCREEN:
				load_screen_loop(all, start_time, offset);
				break ;
			case EDGE_SCREEN:
				break ;
			case CHROME_SCREEN:
				break ;
			case OPERA_SCREEN:
				break ;
			case OPERAGX_SCREEN:
				break ;
			case ERR:
				exit (1);
		}
	}
}
