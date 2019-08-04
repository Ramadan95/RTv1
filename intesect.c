/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intesect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuvalis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 23:37:05 by kkuvalis          #+#    #+#             */
/*   Updated: 2019/08/03 23:37:09 by kkuvalis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double				intersect_ray_plane(t_rtv1 *rtv1, \
							t_vect start, t_vect dir, int i)
{
	double			zero;
	double			dir_dot_c;
	double			cen_dot_c;
	double			t;
	t_vect			help;

	zero = 0.0001;
	help = vector_subt(start, rtv1->sphere[i].center);
	dir_dot_c = dot(dir, rtv1->sphere[i].dir);
	cen_dot_c = dot(help, rtv1->sphere[i].dir);
	if (dir_dot_c == 0.0 || (dir_dot_c < 0 && cen_dot_c < 0) ||
	(dir_dot_c > 0 && cen_dot_c > 0))
		return (-1);
	t = -cen_dot_c / dir_dot_c;
	return (t > zero ? t : -1);
}

double				intersect_ray_cylinder(t_rtv1 *rtv1, \
							t_vect start, t_vect dir, int i)
{
	t_inter_cyl		cyl;

	cyl.zero = 0.0001;
	start = vector_subt(start, rtv1->sphere[i].center);
	cyl.start_dir = dot(start, rtv1->sphere[i].dir);
	cyl.end_dir = dot(dir, rtv1->sphere[i].dir);
	cyl.a = dot(dir, dir) - cyl.end_dir * cyl.end_dir;
	cyl.b = 2 * (dot(dir, start) - cyl.end_dir * cyl.start_dir);
	cyl.c = dot(start, start) - cyl.start_dir * cyl.start_dir -
		rtv1->sphere[i].radius * rtv1->sphere[i].radius;
	cyl.d = cyl.b * cyl.b - 4 * cyl.a * cyl.c;
	if (cyl.d < cyl.zero)
		return (-1);
	cyl.qd = sqrt(cyl.d);
	cyl.t1 = (-cyl.b + cyl.qd) / (2 * cyl.a);
	cyl.t2 = (-cyl.b - cyl.qd) / (2 * cyl.a);
	if (cyl.t1 <= cyl.zero)
		return (-1);
	return ((cyl.t2 > cyl.zero) ? cyl.t2 : cyl.t1);
}

double				intersect_cone_two(t_inter_cone *cone)
{
	if (cone->d < cone->zero)
		return (-1);
	cone->qd = sqrt(cone->d);
	cone->t1 = (-cone->b + cone->qd) / (2 * cone->a);
	cone->t2 = (-cone->b - cone->qd) / (2 * cone->a);
	if ((cone->t1 <= cone->t2 && cone->t1 >= cone->zero) || \
					(cone->t1 >= cone->zero && cone->t2 < cone->zero))
		return (cone->t1);
	if ((cone->t2 <= cone->t1 && cone->t2 >= cone->zero) || \
					(cone->t2 >= cone->zero && cone->t1 < cone->zero))
		return (cone->t2);
	return (-1);
}

double				intersect_ray_cone(t_rtv1 *rtv1, \
							t_vect start, t_vect dir, int i)
{
	t_inter_cone	cone;

	cone.zero = 0.0001;
	start = vector_subt(start, rtv1->sphere[i].center);
	cone.k = tan(rtv1->sphere[i].angle);
	cone.start_dir = dot(start, rtv1->sphere[i].dir);
	cone.end_dir = dot(dir, rtv1->sphere[i].dir);
	cone.a = dot(dir, dir) - (1 + cone.k * cone.k) * \
								cone.end_dir * cone.end_dir;
	cone.b = 2 * (dot(dir, start) - (1 + cone.k * cone.k) * \
								cone.end_dir * cone.start_dir);
	cone.c = dot(start, start) - (1 + cone.k * cone.k) * \
								cone.start_dir * cone.start_dir;
	cone.d = cone.b * cone.b - 4 * cone.a * cone.c;
	return (intersect_cone_two(&cone));
}

double				intersect_ray_sphere(t_rtv1 *rtv1, \
							t_vect start, t_vect dir, int i)
{
	double			r;
	double			t;
	double			discriminant;
	double			t1;
	double			t2;

	r = rtv1->sphere[i].radius;
	start = vector_subt(start, rtv1->sphere[i].center);
	rtv1->k1 = dot(dir, dir);
	rtv1->k2 = dot(start, dir);
	rtv1->k3 = dot(start, start) - r * r;
	discriminant = rtv1->k2 * rtv1->k2 - rtv1->k1 * rtv1->k3;
	if (discriminant < 0)
		return (-1);
	t1 = (-rtv1->k2 + sqrt(discriminant)) / (rtv1->k1);
	t2 = (-rtv1->k2 - sqrt(discriminant)) / (rtv1->k1);
	if (t1 <= 0.0001)
		return (-1);
	t = (t2 > 0) ? t2 : t1;
	return (t);
}
