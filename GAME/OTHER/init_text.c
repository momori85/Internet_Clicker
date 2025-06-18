/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:15:01 by amblanch          #+#    #+#             */
/*   Updated: 2025/06/18 14:38:42 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDE/graph.h"

TTF_Font	*init_text(SDL_Renderer *renderer, SDL_Window *window)
{
	TTF_Font *font = TTF_OpenFont("/nfs/homes/amblanch/.local/share/fonts/Digitalt.ttf", 40);
	if (!font) {
    	fprintf(stderr, "Erreur TTF_OpenFont : %s\n", TTF_GetError());
   		SDL_DestroyRenderer(renderer);
    	SDL_DestroyWindow(window);
   		TTF_Quit();
    	SDL_Quit();
    	return (NULL);
	}
	return (font);
}

void	create_text(TTF_Font *font, SDL_Renderer *renderer, SDL_Window *window, char *text, int pos_x, int pos_y)
{
	int	textWidth = 0;
	int	textHeight = 0;
	SDL_Color textColor = { .r = 255, .g = 100, .b = 255 };
	SDL_Surface *textSurface;
	SDL_Texture *textTexture;

	textSurface = TTF_RenderText_Solid(font, text, textColor);
	if (!textSurface)
	{
    	fprintf(stderr, "Erreur de création de la surface de texte: %s\n", TTF_GetError());
		TTF_CloseFont(font);
   		SDL_DestroyRenderer(renderer);
    	SDL_DestroyWindow(window);
  		TTF_Quit();
		SDL_Quit();
    	return ;
	}
	textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_FreeSurface(textSurface);
    SDL_QueryTexture(textTexture, NULL, NULL, &textWidth, &textHeight);
	SDL_RenderCopy(renderer, textTexture, NULL, &(SDL_Rect){pos_x, pos_y, textWidth, textHeight});
}