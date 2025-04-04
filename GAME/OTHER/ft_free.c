/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:40:27 by mlahonta          #+#    #+#             */
/*   Updated: 2025/04/04 09:44:43 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDE/graph.h"

void	ft_free_textures(t_texture *textures)
{
	t_texture	*i;
	t_texture	*next;

	if (!textures)
		return ;
	i = textures;
	if (i == 0)
		textures = NULL;
	else
	{
		while (i)
		{
			next = i->next;
				SDL_DestroyTexture(i->texture);
			free(i);
			i = next;
		}
		textures = NULL;
	}
}

void	ft_free_rec(t_rect *rectangles)
{
	t_rect	*i;
	t_rect	*next;

	if (!rectangles)
		return ;
	i = rectangles;
	if (i == 0)
		rectangles = NULL;
	else
	{
		while (i)
		{
			next = i->next;
			free(i);
			i = next;
		}
		rectangles = NULL;
	}
}
