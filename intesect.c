#include "rtv1.h"

static double	IntersectRayPlane(t_rtv1 *rtv1, t_vect start, t_vect dir, int i)
{
	double zeroThreshold = 0.0001;
	double dir_dot_c;
	double cen_dot_c;
	double t;
	t_vect help;

	help = vector_subt(start, rtv1->sphere[i].center);
	dir_dot_c = dot(dir, rtv1->sphere[i].dir);
	cen_dot_c = dot(help, rtv1->sphere[i].dir);
	if (dir_dot_c == 0.0 || (dir_dot_c < 0 && cen_dot_c < 0) ||
	(dir_dot_c > 0 && cen_dot_c > 0))
		return (-1);
	t = -cen_dot_c / dir_dot_c;
	return (t > zeroThreshold ? t : -1);
}

double IntersectRayCylinder(t_rtv1 *rtv1, t_vect start, t_vect dir, int i)
{
	double zeroThreshold = 0.0001;

	start = vector_subt(start, rtv1->sphere[i].center);

	double dot_start_cyl_dir = dot(start, rtv1->sphere[i].dir);
	double dot_dir_cyl_dir = dot(dir, rtv1->sphere[i].dir);

	double a = dot(dir, dir) - dot_dir_cyl_dir * dot_dir_cyl_dir;
	double b = 2 * (dot(dir, start) - dot_dir_cyl_dir * dot_start_cyl_dir);
	double c = dot(start, start) - dot_start_cyl_dir * dot_start_cyl_dir -
			rtv1->sphere[i].radius * rtv1->sphere[i].radius;
	double D = b*b - 4*a*c;

	if ( D < zeroThreshold )
		return (-1);
	double qD = sqrt(D);
	double t1 = ( -b + qD)/(2*a);
	double t2 = ( -b - qD)/(2*a);
	if (t1 <= zeroThreshold)
		return (-1);
	double t = (t2 > zeroThreshold) ? t2 : t1;
	return (t);
}

double IntersectRayCone(t_rtv1 *rtv1, t_vect start, t_vect dir, int i)
{
	double zeroThreshold = 0.0001;

	start = vector_subt(start, rtv1->sphere[i].center);
	double k = tan(rtv1->sphere[i].angle);

	double dot_start_cone_dir = dot(start, rtv1->sphere[i].dir);
	double dot_dir_cone_dir = dot(dir, rtv1->sphere[i].dir);

	double a = dot(dir, dir) - (1 + k * k) * dot_dir_cone_dir * dot_dir_cone_dir;
	double b = 2 * (dot(dir, start) - (1 + k * k) * dot_dir_cone_dir * dot_start_cone_dir);
	double c = dot(start, start) - (1 + k * k) * dot_start_cone_dir * dot_start_cone_dir;
	double D = b*b - 4*a*c;

	if ( D < zeroThreshold )
		return (-1);
	double qD = sqrt(D);
	double t1 = ( -b + qD)/(2*a);
	double t2 = ( -b - qD)/(2*a);

	if ((t1 <= t2 && t1 >= zeroThreshold) || (t1 >= zeroThreshold && t2 < zeroThreshold))
		return (t1);
	if ((t2 <= t1 && t2 >= zeroThreshold) || (t2 >= zeroThreshold && t1 < zeroThreshold))
		return (t2);
	return (-1);
}

double		IntersectRaySphere(t_rtv1 *rtv1, t_vect start, t_vect dir, int i)
{
	double	r;
	double	t;
	double	discriminant;
	double	t1;
	double	t2;

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

double  IntersectRayObject(t_rtv1 *rtv1, t_vect start, t_vect dir, int i)
{
	if (rtv1->sphere[i].type == sphere)
		return (IntersectRaySphere(rtv1, start, dir, i));
	else if (rtv1->sphere[i].type == cone)
		return (IntersectRayCone(rtv1, start, dir, i));
	else if (rtv1->sphere[i].type == cylinder)
		return (IntersectRayCylinder(rtv1, start, dir, i));
	else if (rtv1->sphere[i].type == plane)
		return (IntersectRayPlane(rtv1, start, dir, i));
	return (0);
}