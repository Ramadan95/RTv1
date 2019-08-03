/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 05:19:14 by cfahey            #+#    #+#             */
/*   Updated: 2019/08/03 05:19:17 by cfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vect	vec(double x, double y, double z)
{
	t_vect	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vect	vector_subt(t_vect a, t_vect b)
{
	t_vect c;

	c.x = a.x - b.x;
	c.y = a.y - b.y;
	c.z = a.z - b.z;
	return (c);
}

t_vect	vector_sum(t_vect a, t_vect b)
{
	t_vect c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.z = a.z + b.z;
	return (c);
}

t_color	color_sum(t_color a, t_color b)
{
	t_color c;

	c.r = a.r + b.r;
	c.g = a.g + b.g;
	c.b = a.b + b.b;
	if (c.r > 255)
		c.r = 255;
	if (c.g > 255)
		c.g = 255;
	if (c.g > 255)
		c.b = 255;
	return (c);
}

t_vect	vector_project(t_vect a, t_vect b)
{
	double	dota;
	t_vect	project;

	dota = dot(a, b) / dot(b, b);
	project = v_scal_mult(b, dota);
	return (project);
}
