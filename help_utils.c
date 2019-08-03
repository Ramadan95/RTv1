/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 05:35:18 by cfahey            #+#    #+#             */
/*   Updated: 2019/08/03 05:35:19 by cfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		get_closest_object(t_vect start, t_vect dir, \
		double *closest, t_rtv1 *rtv1)
{
	int		i;
	double	b;
	int		sphere_i;

	i = 0;
	sphere_i = -1;
	while (i < rtv1->objcount)
	{
		b = intersect_ray_object(rtv1, start, dir, i);
		if (b < *closest && b != -1)
		{
			*closest = b;
			sphere_i = i;
		}
		i++;
	}
	return (sphere_i);
}

void	put_point(int x, int y, unsigned char *map, t_color rgb)
{
	int index;

	index = (y * WIDTH + x) * 4;
	map[index + 0] = rgb.b;
	map[index + 1] = rgb.g;
	map[index + 2] = rgb.r;
}

void	canvas_to_viewport(t_rtv1 *rtv1, double x, double y)
{
	rtv1->d.x = x * VW / WIDTH;
	rtv1->d.y = y * VH / HEIGHT;
	rtv1->d.z = 1.0;
}

void	err_exit(void)
{
	ft_putendl("error");
	exit(-2);
}
