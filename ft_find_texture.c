/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:57:30 by amblanch          #+#    #+#             */
/*   Updated: 2025/03/28 15:06:52 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && i < n - 1)
	{
		if (s1[i] != s2[i])
			return (((unsigned char)s1[i] - (unsigned char)s2[i]));
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

SDL_Texture	*find_texture(t_texture *texture, char *name)
{
	t_texture *tmp;
	tmp = texture;
	while (tmp)
	{
		if (ft_strncmp(name, tmp->name, strlen(name)) == 0)
			return (tmp->texture);
		tmp = tmp->next;
	}
	return (NULL);
}

SDL_Rect	*find_rect(t_rect *rect, char *name)
{
	t_rect *tmp;
	tmp = rect;
	while (tmp)
	{
		if (ft_strncmp(name, tmp->name, strlen(name)) == 0)
			return (&tmp->rect);
		tmp = tmp->next;
	}
	return (NULL);
}