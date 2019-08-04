/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 05:23:46 by cfahey            #+#    #+#             */
/*   Updated: 2019/08/04 16:23:56 by cfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vect	get_normal(t_rtv1 *rtv1, t_vect p, int i)
{
	t_vect ret;
	t_vect project;
	double k;

	ret = vec(0, 0, 0);
	if (rtv1->sphere[i].type == sphere)
		ret = vector_subt(p, rtv1->sphere[i].center);
	else if (rtv1->sphere[i].type == cone)
	{
		ret = vector_subt(p, rtv1->sphere[i].center);
		project = vector_project(ret, rtv1->sphere[i].dir);
		k = 1 + tan(rtv1->sphere[i].angle) * tan(rtv1->sphere[i].angle);
		project = v_scal_mult(project, k);
		ret = norm(vector_subt(ret, project));
	}
	else if (rtv1->sphere[i].type == cylinder)
	{
		ret = vector_subt(p, rtv1->sphere[i].center);
		project = vector_project(ret, rtv1->sphere[i].dir);
		ret = norm(vector_subt(ret, project));
	}
	else if (rtv1->sphere[i].type == plane)
		ret = rtv1->sphere[i].dir;
	return (ret);
}

t_color	recalc_rgb(t_color rgb, double intencity)
{
	t_color ret;

	ret.r = rgb.r * intencity;
	ret.g = rgb.g * intencity;
	ret.b = rgb.b * intencity;
	if (ret.r > 255)
		ret.r = 255;
	if (ret.g > 255)
		ret.g = 255;
	if (ret.b > 255)
		ret.b = 255;
	return (ret);
}
