/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:32:26 by amblanch          #+#    #+#             */
/*   Updated: 2025/05/27 13:51:50 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../INCLUDE/graph.h"

void	ft_lstadd_back_rect(t_rect **lst, t_rect *new)
{
	t_rect	*i;

	i = *lst;
	if (lst == NULL)
		return ;
	if (*lst == 0)
		*lst = new;
	else
	{
		while (i->next != 0)
			i = i->next;
		i->next = new;
	}
}

void	ft_lstadd_back_rectA(t_rectA **lst, t_rectA *new)
{
	t_rectA	*i;

	i = *lst;
	if (lst == NULL)
		return ;
	if (*lst == 0)
		*lst = new;
	else
	{
		while (i->next != 0)
			i = i->next;
		i->next = new;
	}
}

t_rectA	*ft_lstnew_rectA(int x, int y , int h, int w, float vx, float vy, char *name)
{
	t_rectA	*list;
	SDL_Rect rect = {x, y, h, w};

	list = malloc(sizeof(t_rectA) * 1);
	if (list == 0)
		return (0);
	list->next = NULL;
	list->rect = rect;
	list->name = name;
	list->alpha = 255;
	list->vx = vx;
	list->vy = vy;
	return (list);
}

t_rect	*ft_lstnew_rect(int x, int y , int h, int w, char *name)
{
	t_rect	*list;
	SDL_Rect rect = {x, y, h, w};

	list = malloc(sizeof(t_rect) * 1);
	if (list == 0)
		return (0);
	list->next = NULL;
	list->rect = rect;
	list->name = name;
	return (list);
}

void	ft_lstadd_back_texture(t_texture **lst, t_texture *new)
{
	t_texture	*i;

	i = *lst;
	if (lst == NULL)
		return ;
	if (*lst == 0)
		*lst = new;
	else
	{
		while (i->next != 0)
			i = i->next;
		i->next = new;
	}
}

t_texture	*ft_lstnew_texture(SDL_Texture *texture, char *name)
{
	t_texture	*list;

	list = malloc(sizeof(t_texture) * 1);
	if (list == 0)
		return (0);
	list->next = NULL;
	list->texture = texture;
	list->name = name;
	return (list);
}

void deleteNode(t_rect** lst, char *name)
{
	t_rect	*tmp;
	t_rect *prev = NULL;
	if (lst == NULL || *lst == NULL)
		return;
	tmp = *lst;
	while (lst)
	{
		if (ft_strncmp(tmp->name, name, strlen(name)) == 0)
		{
			if (prev == NULL)
				*lst = tmp->next;
			else
				prev->next = tmp->next;
			free(tmp);
			return ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}
