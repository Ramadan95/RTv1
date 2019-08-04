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
		(pow(cl->r_dot / (len_r * len_v), *s));
}

void	init_cl_and_l(t_cl *cl, t_vect *l)
{
	cl->closest = 99999999.9;
	cl->i = 0;
	cl->intens = 0.0;
	*l = (t_vect){255, 255, 255};
}

void	init_cl_other(t_cl *cl, t_vect l, t_vect n)
{
	cl->n_dot = dot(n, l);
	cl->len_n = (v_length(n));
	cl->len_l = (v_length(l));
}

double	compute_lightning(t_rtv1 *rtv1, t_vect p, t_vect n, double s)
{
	t_vect	l;
	t_vect	r;
	t_cl	cl;

	init_cl_and_l(&cl, &l);
	while (cl.i < rtv1->lightcount)
	{
		if (check_ambient(rtv1, &cl))
			continue;
		l = point_and_directional(rtv1, &cl, p, l);
		init_cl_other(&cl, l, n);
		cl.shadowed = get_closest_object(p, l, &(&cl)->closest, rtv1);
		compute_light2(rtv1, &cl, p, l);
		compute_light1(rtv1, &cl);
		if (s > 0 && cl.shadowed == -1)
		{
			r = reflect_ray(n, l);
			cp(rtv1, &cl, &r, &s);
		}
		cl.i++;
	}
	return (cl.intens);
}

t_color	trace_ray(t_rtv1 *rtv1, t_vect o, t_vect d, double depth)
{
	t_helptrace	t;
	int			sphere_i;
	double		closest;
	double		r;

	closest = 99999999.0;
	sphere_i = get_closest_object(o, d, &closest, rtv1);
	if (sphere_i != -1)
	{
		t.p = vector_sum(o, v_scal_mult(d, closest));
		t.n = get_normal(rtv1, t.p, sphere_i);
		if (dot(t.n, d) > 0)
			t.n = v_scal_mult(t.n, -1);
		tr(rtv1, &t, sphere_i, &r);
		if (depth <= 0 || r <= 0)
			return (t.ret);
		t.ray = reflect_ray(t.n, v_scal_mult(d, -1));
		t.colref = trace_ray(rtv1, t.p, t.ray, depth - 1);
		return (color_sum(recalc_rgb(t.ret, 1 - r),
				recalc_rgb(t.colref, r)));
	}
	else
		return ((t_color) {0, 0, 0});
}
