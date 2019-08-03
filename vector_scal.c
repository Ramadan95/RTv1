/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_scal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 05:20:02 by cfahey            #+#    #+#             */
/*   Updated: 2019/08/03 05:20:05 by cfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vect	norm(t_vect v)
{
	double	n;

	n = sqrt(POWER(v.x) + POWER(v.y) + POWER(v.z));
	v.x = v.x / n;
	v.y = v.y / n;
	v.z = v.z / n;
	return (v);
}

double	v_length(t_vect v)
{
	return (sqrt(dot(v, v)));
}

double	dot(const t_vect v1, const t_vect v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vect	v_scal_mult(t_vect v, double n)
{
	v.x *= n;
	v.y *= n;
	v.z *= n;
	return (v);
}

t_vect	reflect_ray(t_vect a, t_vect b)
{
	return (vector_subt(v_scal_mult(a, dot(a, b) * 2), b));
}
