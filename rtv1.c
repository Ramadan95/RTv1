//
// Created by Calista Fahey on 2019-07-17.
//

#include "rtv1.h"

void		put_point(int x, int y, unsigned char *map, t_color rgb)
{
	int index;

	index = (y * WIDTH + x) * 4;
	map[index + 0] = rgb.b;
	map[index + 1] = rgb.g;
	map[index + 2] = rgb.r;

}

void		CanvasToViewport(t_rtv1 *rtv1, double x, double y)
{
	rtv1->d.x = x * rtv1->Vw / WIDTH;
	rtv1->d.y = y * rtv1->Vh / HEIGHT;
	rtv1->d.z = 1.0;
}

double	dot(const t_vect v1, const t_vect v2)
{
	return (v1.x*v2.x + v1.y*v2.y + v1.z*v2.z);
}

double 	v_length(t_vect v)
{
	return(sqrt(dot(v, v)));
}


double		IntersectRaySphere(t_rtv1 *rtv1, t_vect start, t_vect dir, int i)
{
	//t_vect  c;
	double	r;
	//t_vect	oc;
	double	discriminant;
	double t1;
	double t2;

	//c = rtv1->sphere[i].center;
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
	double t = (t2 > 0) ? t2 : t1;
	return (t);
}

static double	IntersectRayPlane(t_rtv1 *rtv1, t_vect start, t_vect dir, int i)//t_vector start, t_vector dir, t_obj *plane)
{
    double zeroThreshold = 0.0001;
    double dir_dot_c;
    double cen_dot_c;
    double t;
    t_vect help;

    help = vector_subt(start, rtv1->plane[i].pos);
    dir_dot_c = dot(dir, rtv1->plane[i].dir);
    cen_dot_c = dot(help, rtv1->plane[i].dir);
    if (dir_dot_c == 0.0 || (dir_dot_c < 0 && cen_dot_c < 0) || (dir_dot_c > 0 && cen_dot_c > 0))
        return (0);
    t = -cen_dot_c / dir_dot_c;
    return (t > zeroThreshold ? t : 0);
}

double IntersectRayCylinder(t_rtv1 *rtv1, t_vect start, t_vect dir, int i)
{
    double zeroThreshold = 0.0001;

    start = vector_subt(start, rtv1->cyl[i].pos);

    double dot_start_cyl_dir = dot(start, rtv1->cyl->dir);
    double dot_dir_cyl_dir = dot(dir, rtv1->cyl->dir);

    double a = dot(dir, dir) - dot_dir_cyl_dir * dot_dir_cyl_dir;
    double b = 2 * (dot(dir, start) - dot_dir_cyl_dir * dot_start_cyl_dir);
    double c = dot(start, start) - dot_start_cyl_dir * dot_start_cyl_dir - rtv1->cyl->radius * rtv1->cyl->radius;
    double D = b*b - 4*a*c;

    if ( D < zeroThreshold )
        return (0.0);
    double qD = sqrt(D);
    double t1 = ( -b + qD)/(2*a);
    double t2 = ( -b - qD)/(2*a);
    if (t1 <= zeroThreshold)
        return (0.0);
    double t = (t2 >= zeroThreshold) ? t2 : t1;
    return (t);
}

int		get_closest_object(t_vect start, t_vect dir, double *closest, t_rtv1 *rtv1)
{
	int sphere_i;
	int i;
	double b;

	sphere_i = -1;
	i = 0;
 	//sphere_i = -1;
    if (rtv1->name == sphere) {
        while (i < rtv1->objcount) {
            b = IntersectRaySphere(rtv1, start, dir, i);
            if (b < *closest && b != -1) {
                *closest = b;
                sphere_i = i;
            }
            i++;
        }
    }

    if (rtv1->name == plane) {
        while (i < rtv1->objcount) {
            b = IntersectRayPlane(rtv1, start, dir, i);
            if (b < *closest && b != -1) {
                *closest = b;
                sphere_i = i;
            }
            i++;
        }
    }

    if (rtv1->name == cylinder) {
        while (i < rtv1->objcount) {
            b = IntersectRayCylinder(rtv1, start, dir, i);
            if (b < *closest && b != -1) {
                *closest = b;
                sphere_i = i;
            }
            i++;
        }
    }

	return sphere_i;
}


double  ComputeLightning(t_rtv1 *rtv1, t_vect p, t_vect n, double s)
{
    t_vect l;
    double intens;
    double n_dot;
    double r_dot;
	int i;
	double closest = 99999999.9;
	t_vect  r;
	i = 0;
	intens = 0.0;

	l = (t_vect){255, 255, 255};
	while (i < rtv1->lightcount)
	{
		if (rtv1->light[i].type == ambient)
		{
			intens += rtv1->light[i].intens;
			i++;
			continue;
		}
		closest = 99999999.9;
		if (rtv1->light[i].type == point)
			l = vector_subt(rtv1->light[i].pos, p);
		if (rtv1->light[i].type == directional)
		    l = rtv1->light[i].direction;
		n_dot = dot(n, l);
		double len_n = (v_length(n));
		double len_l = (v_length(l));
		if (n_dot > 0 && get_closest_object(p, l, &closest, rtv1) == -1)
    		intens += (rtv1->light[i].intens * n_dot) / (len_n * len_l);
		if (s != -1)
        {
		    r = vector_subt(v_scal_mult(v_scal_mult(n, dot(l, n)), 2), l);
		    r_dot = dot(r, v_scal_mult(rtv1->d, -1));
		    double len_r = (v_length(r));
		    double len_v = v_length(v_scal_mult(rtv1->d, -1));
		    if (r_dot > 0)
		        intens += (rtv1->light[i].intens) * (pow(r_dot/(len_r * len_v), s));
        }
		i++;
	}
   return (intens);
}

t_color recalc_rgb(t_color rgb, double intencity)
{
	t_color ret;

	ret.r = rgb.r * intencity;
	ret.g = rgb.g * intencity;
	ret.b = rgb.b * intencity;

	if (ret.r > 255) ret.r = 255;
	if (ret.g > 255) ret.g = 255;
	if (ret.g > 255) ret.b = 255;

	return ret;
}



t_color	TraceRay(t_rtv1 *rtv1, int min, int max)
{
	t_color ret;
	//int i;
	int sphere_i;
	double closest;
	double b;
	t_vect  p;
	t_vect  n;
	closest = 99999999.0;
    t_vect project;

	sphere_i = get_closest_object(rtv1->o, rtv1->d, &closest, rtv1);
	if (sphere_i != -1 && rtv1->name == sphere)
	{
		p = vector_sum(rtv1->o, v_scal_mult(rtv1->d, closest));
		n = vector_subt(p, rtv1->sphere[sphere_i].center);

		ret = rtv1->sphere[sphere_i].rgb;
		ret = recalc_rgb(ret, ComputeLightning(rtv1, p, n, rtv1->sphere[sphere_i].specular));
        return (ret);
    }
	else if (sphere_i != -1 && rtv1->name == plane)
    {
        p = vector_sum(rtv1->o, v_scal_mult(rtv1->d, closest));
        n = rtv1->plane[sphere_i].dir;
        ret = rtv1->plane[sphere_i].rgb;
        ret = recalc_rgb(ret, ComputeLightning(rtv1, p, n, rtv1->plane[sphere_i].specular));
        return (ret);
    }
	else if (sphere_i != -1 && rtv1->name == cylinder)
    {
        p = vector_sum(rtv1->o, v_scal_mult(rtv1->d, closest));
        n = vector_subt(p, rtv1->cyl[sphere_i].pos);
        project = vector_project(n, rtv1->cyl[sphere_i].dir);
        n = norm(vector_subt(n, project));


        ret = rtv1->cyl[sphere_i].rgb;
        ret = recalc_rgb(ret, ComputeLightning(rtv1, p, n, rtv1->cyl[sphere_i].specular));
        return (ret);
    }
	else
		return  ((t_color){0, 0, 0});
}

void	init(t_rtv1 *rtv1)
{
	rtv1->Vw = 1.0;
	rtv1->Vh = 1.0;
	rtv1->o.x = 0;
	rtv1->o.y = 1.5;
	rtv1->o.z = -4;
	rtv1->objcount = 4;
	rtv1->name = sphere;
}

void    init_sphere(t_rtv1 *rtv1)
{
    rtv1->sphere[0].center.x = 0;
    rtv1->sphere[0].center.y = -1;
    rtv1->sphere[0].center.z = 3;
    rtv1->sphere[0].radius = 1;
    rtv1->sphere[0].color = 0xFF0000;
	rtv1->sphere[0].rgb.r = 255;
	rtv1->sphere[0].rgb.g = 0;
	rtv1->sphere[0].rgb.b = 0;
	rtv1->sphere[0].specular = 500;

	rtv1->sphere[1].center.x = 2;
	rtv1->sphere[1].center.y = 0;
	rtv1->sphere[1].center.z = 4;
	rtv1->sphere[1].radius = 1;
	rtv1->sphere[1].color = 0xFF;
	rtv1->sphere[1].rgb.r = 0;
	rtv1->sphere[1].rgb.g = 0;
	rtv1->sphere[1].rgb.b = 255;
    rtv1->sphere[1].specular = 500;

	rtv1->sphere[2].center.x = -2;
	rtv1->sphere[2].center.y = 0;
	rtv1->sphere[2].center.z = 4;
	rtv1->sphere[2].radius = 1;
	rtv1->sphere[2].color = 0x0FF00;
	rtv1->sphere[2].rgb.r = 0;
	rtv1->sphere[2].rgb.g = 255;
	rtv1->sphere[2].rgb.b = 0;
    rtv1->sphere[2].specular = 500;

	rtv1->sphere[3].center.x = 0;
	rtv1->sphere[3].center.y = -51;
	rtv1->sphere[3].center.z = 0;
	rtv1->sphere[3].radius = 50.0;
	rtv1->sphere[3].color = 0xFFFF00;
	rtv1->sphere[3].rgb.r = 255;
	rtv1->sphere[3].rgb.g = 255;
	rtv1->sphere[3].rgb.b = 0;
    rtv1->sphere[3].specular = 10;
}

void	init_cylinder(t_rtv1 *rtv1)
{
    rtv1->cyl[0].pos.x = 1;
    rtv1->cyl[0].pos.y = 1;
    rtv1->cyl[0].pos.z = 0.1;
    rtv1->cyl[0].dir.x = 1.0;
    rtv1->cyl[0].dir.y = 1.0;
    rtv1->cyl[0].dir.z = 0.1;
    rtv1->cyl[0].rgb.r = 255;
    rtv1->cyl[0].rgb.g = 0;
    rtv1->cyl[0].rgb.b = 255;
    rtv1->cyl[0].specular = 1;
    rtv1->cyl[0].radius = 0.01;
}


void    init_plane(t_rtv1 *rtv1)
{
    rtv1->plane[0].pos.x = -1.0;
    rtv1->plane[0].pos.y = -1.0;
    rtv1->plane[0].pos.z = 0.0;
    rtv1->plane[0].dir.x = 0.0;
    rtv1->plane[0].dir.y = 1.0;
    rtv1->plane[0].dir.z = 0.0;
    rtv1->plane[0].rgb.r = 255;
    rtv1->plane[0].rgb.g = 0;
    rtv1->plane[0].rgb.b = 255;
    rtv1->plane[0].specular = 0;

    rtv1->plane[1].pos.x = -1.0;
    rtv1->plane[1].pos.y = -1.0;
    rtv1->plane[1].pos.z = 0.0;
    rtv1->plane[1].dir.x = 0.0;
    rtv1->plane[1].dir.y = 1.0;
    rtv1->plane[1].dir.z = 0.0;
    rtv1->plane[1].rgb.r = 255;
    rtv1->plane[1].rgb.g = 0;
    rtv1->plane[1].rgb.b = 255;
    rtv1->plane[1].specular = 40;
}

void    init_light(t_rtv1 *rtv1)
{
    rtv1->light[0].type = point;
    rtv1->light[0].intens = 0.32;
    rtv1->light[0].pos = (t_vect){2, 1, 0};


	rtv1->light[1].type = ambient;
    rtv1->light[1].intens = 0.2;

	rtv1->light[2].type = point;
    rtv1->light[2].intens = 0.27;
    rtv1->light[2].pos = (t_vect){-5, 5, 2};

    rtv1->light[3].type = directional;
    rtv1->light[3].intens = 0.2;
    rtv1->light[3].direction = (t_vect){5, 4, 4};

	rtv1->lightcount = 4;
}

int 	main()
{
	t_rtv1 *rtv1;

	rtv1 = malloc(sizeof(t_rtv1));
	SDL_Event event;
	SDL_Renderer *renderer;
	SDL_Window *window;
	SDL_Surface *surface;
	SDL_Texture *texture;

	int x;
	int y;
	init(rtv1);
	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer);
	surface = SDL_CreateRGBSurface(0, WIDTH, HEIGHT, 32, 0, 0, 0, 0);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
	init_sphere(rtv1);
	init_cylinder(rtv1);
	init_plane(rtv1);
	init_light(rtv1);
	int quit = 0;
	while (!quit) {

		x = 0;
		while (++x < WIDTH)
		{
			y = 0;
			while (++y < HEIGHT)
			{
				CanvasToViewport(rtv1, x - WIDTH / 2, -y + HEIGHT / 2);
//				((int *)surface->pixels)[(x + WIDTH / 2 + (y + HEIGHT / 2) * WIDTH)] = 0xFF;
				/*((int *)surface->pixels)[(x + y * WIDTH)] = */put_point(x, y, surface->pixels, TraceRay(rtv1, 1, 100000));
			}
		}
		texture = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_DestroyTexture(texture);
		SDL_RenderPresent(renderer);
		SDL_WaitEvent(&event);
		if (event.type == SDL_QUIT) {
			quit = 1;
		}
		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_DOWN)
			{
				rtv1->o.y -= 0.2;
			}
			else if (event.key.keysym.sym == SDLK_UP)
			{
				rtv1->o.y += 0.2;
			}
			else if (event.key.keysym.sym == SDLK_RIGHT)
			{
				rtv1->o.x += 0.2;
			}
			else if (event.key.keysym.sym == SDLK_LEFT)
			{
				rtv1->o.x -= 0.2;
			}
			else if (event.key.keysym.sym == '=')
			{
				rtv1->o.z += 0.2;
			}
			else if (event.key.keysym.sym == '-')
			{
				rtv1->o.z -= 0.2;
			}
			if (event.key.keysym.sym == SDLK_ESCAPE)
				quit = 1;
		}
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return EXIT_SUCCESS;
}

