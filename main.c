/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:08:46 by amblanch          #+#    #+#             */
/*   Updated: 2025/04/02 17:52:54 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "graph.h"

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

int	main(void)
{
	t_all			all;

	if (init_vars(&all))
		return (1);
	init_rect_for_texture(&all);
	init_texture(&all);
	loading_loop(&all);
	ft_free_textures(all.texture);
	ft_free_rec(all.rect);
	SDL_DestroyRenderer(all.renderer);
	SDL_DestroyWindow(all.window);
	SDL_Quit();
}