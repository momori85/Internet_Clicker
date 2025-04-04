/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:08:46 by amblanch          #+#    #+#             */
/*   Updated: 2025/04/04 14:25:57 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "INCLUDE/graph.h"

int isButtonClicked(SDL_Rect  rect, int mouseX, int mouseY)
{
    return mouseX >= rect.x && mouseX <= rect.x + rect.w &&
           mouseY >= rect.y && mouseY <= rect.y + rect.h;
}

static uint8_t	init_vars(t_all *all)
{
	all->rect = 0;
	all->tmp = SCREEN_HEIGHT / 2;
	all->texture = 0;
	all->status = RUNNING;
	all->button = PLAY_BTN_UP;
	all->render = LOAD_SCREEN;
	all->menu = NONE;
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
		exit (1);
	if (TTF_Init() == -1)
	{
		fprintf(stderr, "Erreur TTF_Init : %s\n", TTF_GetError());
		SDL_Quit();
		return (1);
	}
	all->window = SDL_CreateWindow("CLICKER Internet", 0, 0, 0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP);
	if (!all->window)
		exit(1);
	all->renderer = SDL_CreateRenderer(all->window, -1, SDL_RENDERER_ACCELERATED);
	if (!all->renderer)
		exit(1);
	return (0);
}

void	main_loop(t_all	*all)
{
	Uint32			start_time;
	Uint32			frame_duration;
	int				offset;

	offset = 1;
	while (all->status == RUNNING)
	{
		start_time = SDL_GetTicks();
		switch (all->render)
		{
			case LOAD_SCREEN:
				load_screen_loop(all, &offset);
				break ;
			case MAIN_SCREEN:
				menu_loop(all);
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
				all->status = STOP;
				break ;
		}
		SDL_RenderPresent(all->renderer);
		frame_duration = SDL_GetTicks() - start_time;
		if (frame_duration < 1000 / 60)
			SDL_Delay((1000 / 60) - frame_duration);
	}
}

int	main(void)
{
	t_all			all;

	if (init_vars(&all))
		return (1);
	init_rect_for_texture(&all);
	init_texture(&all);
	main_loop(&all);
	ft_free_textures(all.texture);
	ft_free_rec(all.rect);
	SDL_DestroyRenderer(all.renderer);
	SDL_DestroyWindow(all.window);
	SDL_Quit();
}