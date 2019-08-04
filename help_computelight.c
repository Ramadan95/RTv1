/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_computelight.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuvalis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 00:18:14 by kkuvalis          #+#    #+#             */
/*   Updated: 2019/08/04 00:18:19 by kkuvalis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	compute_light2(t_rtv1 *rtv1, t_cl *cl, t_vect p, t_vect l)
{
	if (rtv1->light[cl->i].type == point && v_length(vector_subt(p,
			rtv1->light[cl->i].pos)) < v_length(v_scal_mult(l, cl->closest)))
		cl->shadowed = -1;
}

void	compute_light1(t_rtv1 *rtv1, t_cl *cl)
{
	if (cl->n_dot > 0 && cl->shadowed == -1)
		cl->intens += (rtv1->light[cl->i].intens * \
			cl->n_dot) / (cl->len_n * cl->len_l);
}

double	check_ambient(t_rtv1 *rtv1, t_cl *cl)
{
	if (rtv1->light[cl->i].type == ambient)
	{
		cl->intens += rtv1->light[cl->i].intens;
		return (cl->i++);
	}
	else
		return (0);
}

t_vect	point_and_directional(t_rtv1 *rtv1, t_cl *cl, t_vect p, t_vect l)
{
	if (rtv1->light[cl->i].type == point)
		l = vector_subt(rtv1->light[cl->i].pos, p);
	if (rtv1->light[cl->i].type == directional)
		l = rtv1->light[cl->i].direction;
	return (l);
}

void	tr(t_rtv1 *rtv1, t_helptrace *t, int sphere_i, double *r)
{
	t->ret = rtv1->sphere[sphere_i].rgb;
	t->ret = recalc_rgb(t->ret, compute_lightning(rtv1, t->p,
			t->n, rtv1->sphere[sphere_i].specular));
	*r = rtv1->sphere[sphere_i].reflect;
}
