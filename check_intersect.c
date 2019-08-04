/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_intersect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuvalis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 23:37:34 by kkuvalis          #+#    #+#             */
/*   Updated: 2019/08/03 23:37:40 by kkuvalis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	intersect_ray_object(t_rtv1 *rtv1, t_vect start, t_vect dir, int i)
{
	if (rtv1->sphere[i].type == sphere)
		return (intersect_ray_sphere(rtv1, start, dir, i));
	else if (rtv1->sphere[i].type == cone)
		return (intersect_ray_cone(rtv1, start, dir, i));
	else if (rtv1->sphere[i].type == cylinder)
		return (intersect_ray_cylinder(rtv1, start, dir, i));
	else if (rtv1->sphere[i].type == plane)
		return (intersect_ray_plane(rtv1, start, dir, i));
	return (0);
}
