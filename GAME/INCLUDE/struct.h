/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:53:07 by mlahonta          #+#    #+#             */
/*   Updated: 2025/04/04 14:14:15 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef enum __attribute__((__packed__)) e_status
{
	RUNNING,
	STOP
}	t_status;

typedef enum __attribute__((__packed__)) e_statusbtn
{
	PLAY_BTN_UP,
	PLAY_BTN_DOWN,
	PLAY_DESTROY
}	t_status_btn;

typedef enum __attribute__((__packed__)) e_status_menu
{
	NONE,
	PLAY_BTN,
	SETTINGS_BTN,
	SAVE_BTN,
	EXIT_BTN,
}	t_status_menu;

typedef enum __attribute__((__packed__)) e_statusrender
{
	LOAD_SCREEN,
	MAIN_SCREEN,
	EDGE_SCREEN,
	CHROME_SCREEN,
	OPERA_SCREEN,
	OPERAGX_SCREEN,
	ERR
}	t_status_render;

typedef struct s_texture
{
	char				*name;
	SDL_Texture			*texture;
	struct s_texture	*next;
}		t_texture;

typedef struct s_rect
{
	char				*name;
	SDL_Rect			rect;
	struct s_rect		*next;
}		t_rect;

typedef struct s_all
{
	t_rect				*rect;
	t_texture			*texture;
	t_status			status;
	t_status_btn		button;
	t_status_menu		menu;
	t_status_render		render;
	SDL_Window			*window;
	SDL_Renderer		*renderer;
	int					tmp;
}		t_all;

#endif
