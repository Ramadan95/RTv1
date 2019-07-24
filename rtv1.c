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
//
//	rtv1->o[0] = rtv1->d[0] + 1;
//	rtv1->o[1] = rtv1->d[1] + 1;
//	rtv1->o[2] = rtv1->d[2] + 1;
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

int		get_closest_object(t_vect start, t_vect dir, double *closest, t_rtv1 *rtv1)
{
	int sphere_i;
	int i;
	double b;

	sphere_i = -1;
	i = 0;
 	//sphere_i = -1;
	while (i < rtv1->objcount)
	{
		b = IntersectRaySphere(rtv1, start, dir, i);
		if (b < *closest && b != -1)
		{
			*closest = b;
			sphere_i = i;
		}
		i++;
	}
	return sphere_i;
}

double  ComputeLightning(t_rtv1 *rtv1, t_vect p, t_vect n)
{
   t_vect l;
   double intens;
   double n_dot;
	int i;
	double closest = 99999999.9;
	i = 0;
	intens = 0.0;

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
		{
			l = vector_subt(rtv1->light[i].pos, p);
		}
		n_dot = dot(n, l);
		double len_n = (v_length(n));
		double len_l = (v_length(l));
		if (n_dot > 0 && get_closest_object(p, l, &closest, rtv1) == -1)
    		intens += (rtv1->light[i].intens * n_dot) / (len_n * len_l);
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

	sphere_i = get_closest_object(rtv1->o, rtv1->d, &closest, rtv1);
	if (sphere_i != -1)
	{
		p = vector_sum(rtv1->o, v_scal_mult(rtv1->d, closest));
		n = vector_subt(p, rtv1->sphere[sphere_i].center);

		ret = rtv1->sphere[sphere_i].rgb;
		ret = recalc_rgb(ret, ComputeLightning(rtv1, p, n));
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
	rtv1->o.y = -0.8;
	rtv1->o.z = 0;
	rtv1->objcount = 4;
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



	rtv1->sphere[1].center.x = 2;
	rtv1->sphere[1].center.y = 0;
	rtv1->sphere[1].center.z = 4;
	rtv1->sphere[1].radius = 1;
	rtv1->sphere[1].color = 0xFF;
	rtv1->sphere[1].rgb.r = 0;
	rtv1->sphere[1].rgb.g = 0;
	rtv1->sphere[1].rgb.b = 255;

	rtv1->sphere[2].center.x = -2;
	rtv1->sphere[2].center.y = -0;
	rtv1->sphere[2].center.z = 4;
	rtv1->sphere[2].radius = 1;
	rtv1->sphere[2].color = 0x00FF00;
	rtv1->sphere[2].rgb.r = 0;
	rtv1->sphere[2].rgb.g = 255;
	rtv1->sphere[2].rgb.b = 0;

	rtv1->sphere[3].center.x = 0;
	rtv1->sphere[3].center.y = -51;
	rtv1->sphere[3].center.z = 0;
	rtv1->sphere[3].radius = 50.0;
	rtv1->sphere[3].color = 0xFFFF00;
	rtv1->sphere[3].rgb.r = 255;
	rtv1->sphere[3].rgb.g = 255;
	rtv1->sphere[3].rgb.b = 0;
}

void    init_light(t_rtv1 *rtv1)
{
    rtv1->light[0].type = point;
    rtv1->light[0].intens = 0.4;
    rtv1->light[0].pos = (t_vect){5, 5, 2};
	

	rtv1->light[1].type = ambient;
    rtv1->light[1].intens = 0.15;

	rtv1->light[2].type = point;
    rtv1->light[2].intens = 0.7;
    rtv1->light[2].pos = (t_vect){-5, 5, 2};
	
	rtv1->lightcount = 3;
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
	init_light(rtv1);
	int quit = 0;
	int i;
	int j;
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

