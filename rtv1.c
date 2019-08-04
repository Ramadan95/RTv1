/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 06:18:34 by cfahey            #+#    #+#             */
/*   Updated: 2019/08/04 17:40:04 by cfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		main(int argc, char **argv)
{
	t_rtv1	rtv1;
	t_sdl	sdl;

	if (argc != 2)
	{
		ft_putstr("Argument is not valid. Please, set number ");
		ft_putendl("of scene in range from 1 to 8 as a argument");
		err_exit();
	}
	init_sdl(&sdl);
	scene_init(&rtv1, argv[1]);
	sdl_run(&sdl, &rtv1);
	SDL_DestroyRenderer(sdl.renderer);
	SDL_DestroyWindow(sdl.window);
	SDL_Quit();
	return (EXIT_SUCCESS);
}
