/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 06:13:55 by cfahey            #+#    #+#             */
/*   Updated: 2019/08/03 06:13:56 by cfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	cp(t_rtv1 *rtv1, t_cl *cl, t_vect *r, const double *s)
{
	double	len_r;
	double	len_v;

	len_r = v_length(*r);
	len_v = v_length(v_scal_mult(rtv1->d, -1));
	cl->r_dot = dot(*r, v_scal_mult(rtv1->d, -1));
	if (cl->r_dot > 0)
		cl->intens += (rtv1->light[cl->i].intens) * \
		(pow(cl->r_dot/(len_r * len_v), *s));
}

double	compute_lightning(t_rtv1 *rtv1, t_vect p, t_vect n, double s)
{
	t_vect	l;
	t_vect	r;
	t_cl	*cl;

	cl = (t_cl *)malloc(sizeof(t_cl));
	cl->closest = 99999999.9;
	cl->i = 0;
	cl->intens = 0.0;
	l = (t_vect){255, 255, 255};
	while (cl->i < rtv1->lightcount)
	{
		if (rtv1->light[cl->i].type == ambient)
		{
			cl->intens += rtv1->light[cl->i].intens;
			cl->i++;
			continue;
		}
		if (rtv1->light[cl->i].type == point)
			l = vector_subt(rtv1->light[cl->i].pos, p);
		if (rtv1->light[cl->i].type == directional)
			l = rtv1->light[cl->i].direction;
		cl->n_dot = dot(n, l);
		cl->len_n = (v_length(n));
		cl->len_l = (v_length(l));
		cl->shadowed = get_closest_object(p, l, &cl->closest, rtv1);
		if (rtv1->light[cl->i].type == point && v_length(vector_subt(p,
				rtv1->light[cl->i].pos)) < v_length(v_scal_mult(l, cl->closest)))
			cl->shadowed = -1;
		if (cl->n_dot > 0 && cl->shadowed == -1)
			cl->intens += (rtv1->light[cl->i].intens *
					cl->n_dot) / (cl->len_n * cl->len_l);
		if (s > 0 && cl->shadowed == -1)
		{
			r = reflect_ray(n, l);
			cp(rtv1, cl, &r, &s);
		}
		cl->i++;
	}
	return (cl->intens);
}

t_color	trace_ray(t_rtv1 *rtv1, t_vect o, t_vect d, double depth)
{
	t_color ret;
	t_vect	p;
	t_vect	n;
	t_vect	ray;
	t_color colref;

	rtv1->tr.closest = 99999999.0;
	rtv1->tr.sphere_i = get_closest_object(o, d, &rtv1->tr.closest, rtv1);
	if (rtv1->tr.sphere_i != -1)
	{
		p = vector_sum(o, v_scal_mult(d, rtv1->tr.closest));
		n = get_normal(rtv1, p, rtv1->tr.sphere_i);
		if (dot(n, d) > 0)
			n = v_scal_mult(n, -1);
		ret = rtv1->sphere[rtv1->tr.sphere_i].rgb;
		ret = recalc_rgb(ret, compute_lightning(rtv1,
				p, n, rtv1->sphere[rtv1->tr.sphere_i].specular));
		rtv1->tr.r = rtv1->sphere[rtv1->tr.sphere_i].reflect;
		if (depth <= 0 || rtv1->tr.r <= 0)
			return (ret);
		ray = reflect_ray(n, v_scal_mult(d, -1));
		colref = trace_ray(rtv1, p, ray, depth - 1);
		return (color_sum(recalc_rgb(ret, 1 - rtv1->tr.r),
				recalc_rgb(colref, rtv1->tr.r)));
	}
	else
		return ((t_color){0, 0, 0});
}
