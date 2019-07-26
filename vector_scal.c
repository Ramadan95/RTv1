//
// Created by Calista Fahey on 2019-07-18.
//

#include "rtv1.h"

t_vect	v_scal_plus(t_vect v, double n)
{
	v.x += n;
	v.y += n;
	v.z += n;

	return (v);
}

t_vect	v_scal_minus(t_vect v, double n)
{
	v.x -= n;
	v.y -= n;
	v.z -= n;

	return (v);
}

t_vect	v_scal_mult(t_vect v, double n)
{
	v.x *= n;
	v.y *= n;
	v.z *= n;

	return (v);
}

t_vect	v_scal_div(t_vect v, double n)
{
	v.x /= n;
	v.y /= n;
	v.z /= n;

	return (v);
}