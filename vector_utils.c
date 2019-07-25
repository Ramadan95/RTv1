//
// Created by Calista Fahey on 2019-07-18.
//

#include "rtv1.h"

t_vect	v_matr_mult(double mat[4][4], t_vect v)
{
	t_vect	ret;

	ret.x = (mat[0][0] * v.x) + (mat[1][0] * v.y) +
			(mat[2][0] * v.z) + (mat[3][0] * 1);
	ret.y = (mat[0][1] * v.x) + (mat[1][1] * v.y) +
			(mat[2][1] * v.z) + (mat[3][1] * 1);
	ret.z = (mat[0][2] * v.x) + (mat[1][2] * v.y) +
			(mat[2][2] * v.z) + (mat[3][2] * 1);
	return (ret);
}

t_vect	norm(t_vect v)
{
	double	n;

	n = sqrt(defpow(v.x) + defpow(v.y) + defpow(v.z));
	v.x = v.x / n;
	v.y = v.y / n;
	v.z = v.z / n;
	return (v);
}
t_vect  vector_mult(t_vect a, t_vect b)
{
    t_vect c;

    c.x = a.y * b.z - a.z * b.y;
    c.y = a.z * b.x - a.x * b.z;
    c.z = a.x * b.y - a.y * b.x;
    return (c);
}

double	v_distance(t_vect v1, t_vect v2)
{
	return (sqrt(defpow(v1.x - v2.x)) + sqrt(defpow(v1.y - v2.y)) + sqrt(defpow(v1.z - v2.z)));
}

t_vect		vec(double x, double y, double z)
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
