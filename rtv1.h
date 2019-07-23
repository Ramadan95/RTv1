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

# define WIDTH 1024
# define HEIGHT 768

# define pow(x) x * x

typedef struct		s_vect
{
	double			x;
	double			y;
	double			z;
}					t_vect;

typedef	struct		s_color
{
	double			r;
	double			g;
	double			b;
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
	double			center[3];
	double			radius;
	double			color;
}					t_sphere;

typedef struct		s_rtv1
{
	t_sphere		*sphere;
	double			a;
	double			b;
	double			o[3];
	double 			d[3];
	double 			v1[3];
	double 			v2[3];
	double			t[2];
	int 			objcount;
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

#endif //RTV1_SDL_H
