//
// Created by Calista Fahey on 2019-07-16.
//

#ifndef RTV1_SDL_H
# define RTV1_SDL_H

# include "frameworks/SDL2.framework/Headers/SDL.h"
# include <fcntl.h>
# include <zconf.h>
# include <stdio.h>
# include <stdlib.h>
# include "gnl/libft/libft.h"
# include "gnl/get_next_line.h"
# include <math.h>
# define WIDTH 1000
# define HEIGHT 1000
# define Vw 1
# define Vh 1

# define defpow(x) x * x

typedef enum
{
	point,
	directional,
	ambient
}			t_light_type;

typedef enum
{
    sphere,
    cone,
    plane,
    cylinder
}			t_object;

typedef struct		s_sdl
{
	SDL_Event		event;
	SDL_Renderer	*renderer;
	SDL_Window		*window;
	SDL_Surface		*surface;
	SDL_Texture		*texture;
}					t_sdl;

typedef struct		s_vect
{
	double			x;
	double			y;
	double			z;
}					t_vect;

typedef	struct		s_color
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}					t_color;

typedef struct		s_cl
{
	double	intens;
	double	len_l;
	double	len_n;
	int		shadowed;
	double	n_dot;
	double	r_dot;
	int		i;
	double	closest;
}					t_cl;

typedef struct		s_tr
{
	int				sphere_i;
	double			closest;
	double			r;
}					t_tr;

typedef struct		s_cam
{
	t_vect			origin;
	t_vect			rotate;
	double			aspect_ratio;
	double			fov;
}					t_cam;

typedef struct	    s_camera
{
    t_vect			center;
    t_vect			dir;
}				    t_camera;

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
    int             type;
	t_vect			center;
	t_vect          dir;
	t_color			rgb;
	double			view_alpha;
	double			view_beta;
//	double			center[3];
	double			radius;
	double			color;
	double          specular;
	double          reflect;
	double          angle;

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
	t_tr			tr;
	t_camera		camera;
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
//	double			Vw;
//	double			Vh;
	double			color;
	int				v_size;
	int				p_plane;
	int				x;
	int				y;
}					t_rtv1;

t_color	trace_ray(t_rtv1 *rtv1, t_vect o, t_vect d, double depth);
int		get_closest_object(t_vect start, t_vect dir, double *closest, t_rtv1 *rtv1);
double  IntersectRayObject(t_rtv1 *rtv1, t_vect start, t_vect dir, int i);
void	put_point(int x, int y, unsigned char *map, t_color rgb);
void	canvas_to_viewport(t_rtv1 *rtv1, double x, double y);
void	read_scene(t_rtv1 *rtv1, char *file_name);
void	scene_init(t_rtv1 *rtv1, char *number);
void	set_start_angles(t_rtv1 *scene);
double 	v_length(t_vect v);
t_vect  get_normal(t_rtv1 *rtv1, t_vect p, int i);
t_vect  reflect_ray(t_vect a, t_vect b);
t_color recalc_rgb(t_color rgb, double intencity);
t_vect	read_vector(char *str);
t_vect	vector_subt(t_vect a, t_vect b);
t_vect	vector_sum(t_vect a, t_vect b);
t_vect	v_scal_mult(t_vect v, double n);
t_vect	vec(double x, double y, double z);
t_vect  vector_mult(t_vect a, t_vect b);
t_color	v_color_mult(t_color v, double n);
t_color	color_sum(t_color a, t_color b);
t_vect	vector_project(t_vect a, t_vect b);
double	dot(const t_vect v1, const t_vect v2);
void	set_light_type(char *line, t_light *light);
t_rtv1	*read_obj_parameters(char *line, t_rtv1 **obj);
t_light	*read_light_parameters(char *line, t_light **light);
t_rtv1	*camera_init(char *line, t_rtv1 *rtv1);
void	set_obj_type(char *line, t_rtv1 *obj);
double	ft_atof(char *str);
t_vect	norm(t_vect v);
void 	init_sdl(t_sdl *sdl);
void 	sdl_reinit(t_sdl *sdl);
void 	sdl_run(t_sdl *sdl, t_rtv1 *rtv1);
void 	sdl_keydown(t_rtv1 *rtv1, t_sdl *sdl, int *quit);
void	err_exit(void);

#endif //RTV1_SDL_H
