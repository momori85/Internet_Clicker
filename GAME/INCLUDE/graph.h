/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:54:05 by amblanch          #+#    #+#             */
/*   Updated: 2025/04/04 09:48:21 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_H
# define GRAPH_H

# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_ttf.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include "struct.h"

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080

int 	isButtonClicked(SDL_Rect  rect, int mouseX, int mouseY);
void	process_screen(t_all *all, t_status_render status);

int	ft_strncmp(const char *s1, const char *s2, size_t n);

void	ft_lstadd_back_rect(t_rect **lst, t_rect *new);
t_rect	*ft_lstnew_rect(int x, int y , int h, int w, char *name);


void	ft_lstadd_back_texture(t_texture **lst, t_texture *new);
t_texture	*ft_lstnew_texture(SDL_Texture *texture, char *name);


SDL_Texture	*LoadTexture(const char *file, SDL_Renderer *renderer);
SDL_Texture	*find_texture(t_texture *texture, char *name);
SDL_Rect	*find_rect(t_rect *rect, char *name);


void	deleteNode(t_rect** lst, char *name);
void	ft_free_textures(t_texture *textures);
void	ft_free_rec(t_rect *rectangles);

void	init_rect_for_texture(t_all *all);
void	init_texture(t_all *all);


TTF_Font	*init_text(SDL_Renderer *renderer, SDL_Window *window);
void	craete_text(TTF_Font *font, SDL_Renderer *renderer, SDL_Window *window, char *text, int pos_x, int pos_y);
void	loading_loop(t_all *all);

#endif