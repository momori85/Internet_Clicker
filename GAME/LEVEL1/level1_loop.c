/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level1_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaury <amaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:49:00 by amblanch          #+#    #+#             */
/*   Updated: 2025/06/13 20:40:42 by amaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../INCLUDE/graph.h"

void	level1_loop_event(t_all *all)
{
	int mouse = 0;
	int	mouse_x = 0;
	int mouse_y = 0;
	int width;
    int height;
	SDL_Event	event;

	while (SDL_PollEvent(&event))
	{
		mouse_x = event.button.x;
		mouse_y = event.button.y;
		if (event.type == SDL_QUIT)
			all->status = STOP;
		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_ESCAPE)
				all->status = STOP;
		}
		if (event.type == SDL_WINDOWEVENT)
		{
        	if (event.window.event == SDL_WINDOWEVENT_RESIZED)
			{
            	width = event.window.data1;
            	height = event.window.data2;
				SDL_GetWindowSize(all->window, &width, &height);
				new_size_texture(all, width, height);
			}
        }
		if (event.type == SDL_MOUSEBUTTONDOWN)
		{
            if (event.button.button == SDL_BUTTON_LEFT)
			{
                if (!mouse) 
				{
					if (isButtonClicked(*find_rect(all->rect, "bg_level1"), mouse_x, mouse_y))
					{
						Mix_PlayChannel(-1, all->click, 0);
						float angle = (rand() % 360) * 3.14 / 180.0f;
						float rayon = 0 + rand() % 120;

						float x  = mouse_x + cosf(angle) * rayon;
						float y  = mouse_y + sinf(angle) * rayon;
						float vx = ((rand() % 200) - 100) / 100.0f;
						float vy = -3.0f - (rand() % 100) / 100.0f;
						all->nb_count++;
						ft_lstadd_back_rectA(&all->clicker_rec, ft_lstnew_rectA(x, y, 100, 100, vx, vy, "prop_lvl1"));
					}
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

void delete_node(t_rectA **head)
{
    if (!head || !*head)
        return ;

    t_rectA *curr = *head;
    *head = curr->next;
    free(curr);
}

void	level1_loop(t_all *all)
{
	int count;
	int width;
    int height;
	SDL_Rect	dst;
	char	buf[64];

	count = 0;
	level1_loop_event(all);
	SDL_RenderClear(all->renderer);
	SDL_RenderCopy(all->renderer, find_texture(all->texture, "bg_level1"), NULL, find_rect(all->rect, "bg_level1"));
	SDL_RenderCopy(all->renderer, find_texture(all->texture, "logo_fond_level1"), NULL, find_rect(all->rect, "logo_level1"));
	t_rectA	*rec;
	rec = all->clicker_rec;
	if (rec && rec->rect.y <= -200)
		delete_node(&all->clicker_rec);
	while(rec)
	{
		if (count >= 20)
		{
			delete_node(&all->clicker_rec);
			break ;
		}
		else
		{
			SDL_SetTextureAlphaMod(find_texture(all->texture, "logo_level1"), rec->alpha);
			SDL_RenderCopy(all->renderer, find_texture(all->texture, "logo_level1"), NULL, &rec->rect);
			rec->x += rec->vx * 1;
        	rec->y += rec->vy * 1;
			rec->x += ((rand() % 3) - 1) * 0.1f;
			if (rec->alpha > 2) rec->alpha -= 2;
			else              rec->alpha  = 0;
			rec->rect.y -= 3;
			if (rec->alpha > 1)
				rec->alpha -= 2;
		}
		if (rec)
			rec = rec->next;
		count++;
	}
	SDL_Surface *surf = TTF_RenderText_Blended(all->counter, SDL_itoa(all->nb_count, buf, 10), all->counter_color);
	if (!surf)
	{
	    fprintf(stderr, "Erreur TTF_RenderText: %s\n", TTF_GetError());
	    return ;
	}
	if (all->counter_texture) SDL_DestroyTexture(all->counter_texture);
	all->counter_texture = SDL_CreateTextureFromSurface(all->renderer, surf);
	SDL_GetWindowSize(all->window, &width, &height);
	dst.x = (width - surf->w - 20);
	dst.y = 20;
	dst.w = surf->w;
	dst.h = surf->h;
	SDL_FreeSurface(surf);
	SDL_RenderCopy(all->renderer, all->counter_texture, NULL, &dst);
}