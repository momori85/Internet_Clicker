/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_screens.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:28:37 by mlahonta          #+#    #+#             */
/*   Updated: 2025/04/04 14:23:55 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDE/graph.h"

void	process_rgb(t_all *all, t_status_render status)
{
	static float 	t = 0.0f;
	const float 	transition_speed = 0.01f;
	float			shadow_factor;
	uint16_t		y;
	Uint8			r;
	Uint8			g;
	Uint8			b;
	Uint8			r_old;
	Uint8			g_old;
	Uint8			b_old;

	if (status == LOAD_SCREEN && all->button == PLAY_BTN_UP)
	{
		y = 0;
		while (y < SCREEN_HEIGHT)
		{
			r = (Uint8)(y * 255 / SCREEN_HEIGHT);
			b = (Uint8)((SCREEN_HEIGHT - y) * 255 / SCREEN_HEIGHT);

			SDL_SetRenderDrawColor(all->renderer, r, 0, b, 255);
			SDL_RenderDrawLine(all->renderer, 0, y, SCREEN_WIDTH, y);
			y++;
		}
	}
	if (all->button == PLAY_BTN_DOWN)
	{
		Uint8 final_r = 0x85;
		Uint8 final_g = 0x67;
		Uint8 final_b = 0xF7;
	
		y = 0;
		while (y < SCREEN_HEIGHT)
		{
			r_old = (Uint8)(y * 255 / SCREEN_HEIGHT);
			g_old = 0;
			b_old = (Uint8)((SCREEN_HEIGHT - y) * 255 / SCREEN_HEIGHT);
	
			r = (Uint8)((1 - t) * r_old + t * final_r);
			g = (Uint8)((1 - t) * g_old + t * final_g);
			b = (Uint8)((1 - t) * b_old + t * final_b);
	
			shadow_factor = (float)y / (SCREEN_HEIGHT - 300);
			shadow_factor = shadow_factor * shadow_factor * 0.5f;
	
			r = (Uint8)(r * (1.0f - shadow_factor));
			g = (Uint8)(g * (1.0f - shadow_factor));
			b = (Uint8)(b * (1.0f - shadow_factor));
	
			SDL_SetRenderDrawColor(all->renderer, r, g, b, 255);
			SDL_RenderDrawLine(all->renderer, 0, y, SCREEN_WIDTH, y);
			y++;
		}
		if (t < 1.0f)
			t += transition_speed;
	}
	if (transition_speed == 1)
		all->render = MAIN_SCREEN;
}

void	process_screen(t_all *all, t_status_render status)
{
	process_rgb(all, status);
	if (status == LOAD_SCREEN)
	{
		SDL_RenderCopy(all->renderer, find_texture(all->texture, "title"), NULL, find_rect(all->rect, "title"));
		SDL_RenderCopy(all->renderer, find_texture(all->texture, "play"), NULL, find_rect(all->rect, "play"));
		SDL_RenderCopy(all->renderer, find_texture(all->texture, "meme"), NULL, find_rect(all->rect, "meme"));
		SDL_RenderCopy(all->renderer, find_texture(all->texture, "meme1"), NULL, find_rect(all->rect, "meme1"));
		SDL_RenderCopy(all->renderer, find_texture(all->texture, "meme2"), NULL, find_rect(all->rect, "meme2"));
		SDL_RenderCopy(all->renderer, find_texture(all->texture, "meme3"), NULL, find_rect(all->rect, "meme3"));
		SDL_RenderCopy(all->renderer, find_texture(all->texture, "meme4"), NULL, find_rect(all->rect, "meme4"));
		SDL_RenderCopy(all->renderer, find_texture(all->texture, "meme5"), NULL, find_rect(all->rect, "meme5"));
		SDL_RenderCopy(all->renderer, find_texture(all->texture, "meme6"), NULL, find_rect(all->rect, "meme6"));
		SDL_RenderCopy(all->renderer, find_texture(all->texture, "cat_left"), NULL, find_rect(all->rect, "cat_left"));
		SDL_RenderCopy(all->renderer, find_texture(all->texture, "cat_right"), NULL, find_rect(all->rect, "cat_right"));
	}
	if (status == MAIN_SCREEN)
		return ;
}
