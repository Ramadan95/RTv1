//
// Created by Calista Fahey on 2019-07-16.
//

#ifndef RTV1_SDL_H
# define RTV1_SDL_H

# include "frameworks/SDL2.framework/Headers/SDL.h"
# include <stdio.h>
# include <stdlib.h>
# include "parser.h"
# include "gnl/libft/libft.h"
# include "gnl/get_next_line.h"
# include <math.h>

# define WIDTH 1000
# define HEIGHT 1000

# define defpow(x) x * x

typedef enum
{
	point,
	directional,
	ambient
}			t_light_type;

typedef struct		s_vect
{
	double			x;
	double			y;
	double			z;
}					t_vect;

typedef	struct		s_color
{
	unsigned int			r;
	unsigned int			g;
	unsigned int			b;
}					t_color;

typedef struct		s_ray
{
	t_vect			org;
	t_vect			dir;
}					t_ray;

typedef struct		s_cam
{
	t_vect			origin;
	t_vect			rotate;
	double			aspect_ratio;
	double			fov;
}					t_cam;

typedef	struct		s_chape
{
	int 			type;
	t_color			color;
	t_vect			c;
	t_vect			d;

	double			sph_r;
}					t_shape;

typedef	struct		s_scene
{
	t_shape			*obj;
	int 			num_shape;

	double			ambient;
}					t_scene;

typedef	struct		s_sphere
{
	t_vect			center;
	t_color			rgb;
//	double			center[3];
	double			radius;
	double			color;
	double          specular;
	double          reflect;
}					t_sphere;

typedef struct      s_light
{
    int             type;
    double          intens;
    t_vect          pos;
    t_vect          direction;
}                   t_light;

typedef struct		s_rtv1
{
	t_sphere		sphere[100];
	t_light         light[100];
	double			a;
	double			b;
	t_vect			o;
	t_vect 			d;
	double 			v1[3];
	double 			v2[3];
	double			t[2];
	int 			objcount;
	int				lightcount;
	int 			obj;
	double			k1;
	double			k2;
	double			k3;
//	double			t;
	double			Vw;
	double			Vh;
	double			color;
	int				v_size;
	int				p_plane;
	int				x;
	int				y;
}					t_rtv1;


t_vect	vector_subt(t_vect a, t_vect b);
t_vect	vector_sum(t_vect a, t_vect b);
t_vect	v_scal_mult(t_vect v, double n);
t_vect  vector_mult(t_vect a, t_vect b);
t_color	v_color_mult(t_color v, double n);
t_color	color_sum(t_color a, t_color b);
t_vect	norm(t_vect v);

#endif //RTV1_SDL_H
