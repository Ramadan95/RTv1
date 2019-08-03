/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 06:14:53 by cfahey            #+#    #+#             */
/*   Updated: 2019/08/03 06:14:54 by cfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	init_sdl(t_sdl *sdl)
{
	SDL_Event		event;
	SDL_Renderer	*renderer;
	SDL_Window		*window;
	SDL_Surface		*surface;
	SDL_Texture		*texture;

	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer);
	surface = SDL_CreateRGBSurface(0, WIDTH, HEIGHT, 32, 0, 0, 0, 0);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_DestroyTexture(texture);
	SDL_RenderPresent(renderer);
	SDL_WaitEvent(&event);
	sdl->event = event;
	sdl->renderer = renderer;
	sdl->window = window;
	sdl->surface = surface;
	sdl->texture = texture;
}

void	sdl_reinit(t_sdl *sdl)
{
	sdl->texture = SDL_CreateTextureFromSurface(sdl->renderer, sdl->surface);
	SDL_RenderClear(sdl->renderer);
	SDL_RenderCopy(sdl->renderer, sdl->texture, NULL, NULL);
	SDL_DestroyTexture(sdl->texture);
	SDL_RenderPresent(sdl->renderer);
	SDL_WaitEvent(&sdl->event);
}

void	sdl_keydown(t_rtv1 *rtv1, t_sdl *sdl, int *quit)
{
	if (sdl->event.type == SDL_KEYDOWN)
	{
		if (sdl->event.key.keysym.sym == SDLK_DOWN)
			rtv1->o.y -= 0.2;
		else if (sdl->event.key.keysym.sym == SDLK_UP)
			rtv1->o.y += 0.2;
		else if (sdl->event.key.keysym.sym == SDLK_RIGHT)
			rtv1->o.x += 0.2;
		else if (sdl->event.key.keysym.sym == SDLK_LEFT)
			rtv1->o.x -= 0.2;
		else if (sdl->event.key.keysym.sym == '=')
			rtv1->o.z += 0.2;
		else if (sdl->event.key.keysym.sym == '-')
			rtv1->o.z -= 0.2;
		if (sdl->event.key.keysym.sym == SDLK_ESCAPE)
			*quit = 1;
	}
}

void	sdl_run(t_sdl *sdl, t_rtv1 *rtv1)
{
	int		quit;
	double	rec_depth;
	int		x;
	int		y;

	quit = 0;
	rec_depth = 3;
	while (!quit)
	{
		x = 0;
		while (++x < WIDTH)
		{
			y = 0;
			while (++y < HEIGHT)
			{
				canvas_to_viewport(rtv1, x - WIDTH / 2, -y + HEIGHT / 2);
				put_point(x, y, sdl->surface->pixels,
						trace_ray(rtv1, rtv1->o, rtv1->d, rec_depth));
			}
		}
		sdl_reinit(sdl);
		if (sdl->event.type == SDL_QUIT)
			quit = 1;
		sdl_keydown(rtv1, sdl, &quit);
	}
}

int		clean_exit(t_sdl *sdl)
{
	SDL_DestroyRenderer(sdl->renderer);
	SDL_DestroyWindow(sdl->window);
	SDL_Quit();
	exit(-2);
}
