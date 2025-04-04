/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rect_for_texture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:12:59 by amblanch          #+#    #+#             */
/*   Updated: 2025/04/04 14:32:27 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../INCLUDE/graph.h"

void	init_rect_for_texture(t_all *all)
{
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(0, 0, 1920, 1080, "loading"));
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(469, 487, 300, 210, "cat_left"));
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(1147, 487, 300, 210, "cat_right"));
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(0, 0, 87, 11, "loading_bar"));
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(253, 771, 182, 206, "meme"));
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(714, 914, 157, 157, "meme1"));
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(1598, 565, 253, 184, "meme2"));
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(1214, 791, 186, 245, "meme3"));
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(80, 69, 201, 485, "meme4"));
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(1215, 97, 338, 230, "meme5"));
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(492, 97, 277, 252, "meme6"));
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(960, 900, 91, 41, "play"));
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(750, 414, 572, 252, "title"));
}

void	init_texture(t_all *all)
{
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/LOADING/loading.png", all->renderer), "loading"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/LOADING/cat_left.png", all->renderer), "cat_left"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/LOADING/cat_right.png", all->renderer), "cat_right"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/LOADING/loading_bar.png", all->renderer), "loading_bar"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/LOADING/meme.png", all->renderer), "meme"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/LOADING/meme1.png", all->renderer), "meme1"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/LOADING/meme2.png", all->renderer), "meme2"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/LOADING/meme3.png", all->renderer), "meme3"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/LOADING/meme4.png", all->renderer), "meme4"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/LOADING/meme5.png", all->renderer), "meme5"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/LOADING/meme6.png", all->renderer), "meme6"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/LOADING/play.png", all->renderer), "play"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/LOADING/tilte.png", all->renderer), "title"));
}

void	init_rect_for_texture_menu(t_all *all)
{
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(726, 856, 470, 105, "exit_bar"));
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(740, 414, 442, 105, "play_bar"));
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(715, 705, 490, 105, "save_bar"));
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(547, 560, 826, 105, "settings_bar"));
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(597, 11, 728, 309, "title_menu"));
}

void	init_texture_menu(t_all *all)
{
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/MENU/exit_bar.png", all->renderer), "exit_bar"));
	SDL_SetTextureBlendMode(find_texture(all->texture, "exit_bar"), SDL_BLENDMODE_BLEND);
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/MENU/play_bar.png", all->renderer), "play_bar"));
	SDL_SetTextureBlendMode(find_texture(all->texture, "play_bar"), SDL_BLENDMODE_BLEND);
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/MENU/save_bar.png", all->renderer), "save_bar"));
	SDL_SetTextureBlendMode(find_texture(all->texture, "save_bar"), SDL_BLENDMODE_BLEND);
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/MENU/settings_bar.png", all->renderer), "settings_bar"));
	SDL_SetTextureBlendMode(find_texture(all->texture, "settings_bar"), SDL_BLENDMODE_BLEND);
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/MENU/title.png", all->renderer), "title_menu"));
	SDL_SetTextureBlendMode(find_texture(all->texture, "title_menu"), SDL_BLENDMODE_BLEND);
}