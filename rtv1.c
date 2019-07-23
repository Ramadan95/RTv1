//
// Created by Calista Fahey on 2019-07-17.
//

#include "rtv1.h"

void		CanvasToViewport(t_rtv1 *rtv1, double x, double y)
{
	rtv1->d[0] = x * rtv1->Vw / WIDTH;
	rtv1->d[1] = y * rtv1->Vh / HEIGHT;
	rtv1->d[2] = 1.0;
}

//int 	lenght(t_rtv1 *rtv1)
//{
//
//}

double	dot(const double v1[3], const double v2[3])
{
	return (v1[0]*v2[0] + v1[1]*v2[1] + v1[2]*v2[2]);
}

double		IntersectRaySphere(t_rtv1 *rtv1, int i)
{
	double  c[3];
	double	r;
	double	oc[3];
	double	discriminant;

	c[0] = rtv1->sphere[i].center[0];
	c[1] = rtv1->sphere[i].center[1];
	c[2] = rtv1->sphere[i].center[2];
	r = rtv1->sphere[i].radius;
	oc[0] = rtv1->o[0] - c[0];
	oc[1] = rtv1->o[1] - c[1];
	oc[2] = rtv1->o[2] - c[2];

	rtv1->k1 = dot(rtv1->d, rtv1->d);
	rtv1->k2 =  dot(oc, rtv1->d);
	rtv1->k3 = dot(oc, oc) - r * r;

	discriminant = rtv1->k2 * rtv1->k2 -  rtv1->k1 * rtv1->k3;
	if (discriminant < 0)
	{
		return (0);
	}
	else {
		rtv1->t[0] = (-rtv1->k2 + sqrt(discriminant) / (rtv1->k1));
		rtv1->t[1] = (-rtv1->k2 - sqrt(discriminant) / (rtv1->k1));
	}
	if (rtv1->t[0] < 0) {
		return (0);
	}
	double t = (rtv1->t[1] > 0) ? rtv1->t[1] : rtv1->t[0];
	return (t);
}

//double IntersectRaySphere(t_rtv1 * rtv1)//double3 start, double3 dir, t_cl_obj *obj)
//{
//	double zeroThreshold = 0.0001;
//
//	start = start - obj->center;
//	double a = dot(dir, dir);
//	double b = dot(start, dir);
//	double c = dot(start, start) - obj->radius * obj->radius;
//	double D = b*b -a*c;
//
//	if ( D < zeroThreshold )
//		return (0.0);
//	double qD = sqrt(D);
//	double t1 = ( -b + qD)/(a);
//	double t2 = ( -b - qD)/(a);
//	if (t1 <= zeroThreshold)
//		return (0.0);
//	double t = (t2 > zeroThreshold) ? t2 : t1;
//	return (t);
//}

int	TraceRay(t_rtv1 *rtv1, int min, int max)
{
	int i;
	int sphere_i;
	double closest;
	double b;
	closest = 99999999.0;
 	i = 0;
 	sphere_i = -1;
//	if (rtv1->t[0] >= min && rtv1->t[0] <= max && rtv1->t[0] < b)
//	    b = rtv1->t[0];
//  if (rtv1->t[1] >= min && rtv1->t[1] <= max && rtv1->t[1] < b)
//        b = rtv1->t[1];
	while (i < rtv1->objcount)
	{
		b = IntersectRaySphere(rtv1, i);
		if (b < closest && b != 0)
		{
			closest = b;
			sphere_i = i;
		}
		i++;
	}
	if (sphere_i != -1)
		return ((int)rtv1->sphere[sphere_i].color);
	else
		return  (0x0);
}

void	init(t_rtv1 *rtv1)
{
//	rtv1->v_size = 1;
//	rtv1->p_plane = 1;
	rtv1->Vw = 1.33333;
	rtv1->Vh = 1.0;
	rtv1->o[0] = 0;
	rtv1->o[1] = 0;
	rtv1->o[2] = -5;
	rtv1->objcount = 4;
}

void    init_sphere(t_rtv1 *rtv1)
{
    rtv1->sphere[0].center[0] = 0;
    rtv1->sphere[0].center[1] = -1;
    rtv1->sphere[0].center[2] = 3;
    rtv1->sphere[0].radius = 1;
    rtv1->sphere[0].color = 0xFF0000;

	rtv1->sphere[1].center[0] = 2;
	rtv1->sphere[1].center[1] = 0;
	rtv1->sphere[1].center[2] = 4;
	rtv1->sphere[1].radius = 1;
	rtv1->sphere[1].color = 0xFF;

	rtv1->sphere[2].center[0] = -2;
	rtv1->sphere[2].center[1] = 0;
	rtv1->sphere[2].center[2] = 4;
	rtv1->sphere[2].radius = 1;
	rtv1->sphere[2].color = 0x00FF00;

	rtv1->sphere[3].center[0] = 0;
	rtv1->sphere[3].center[1] = -51;
	rtv1->sphere[3].center[2] = 3;
	rtv1->sphere[3].radius = 50.0;
	rtv1->sphere[3].color = 0xFFFF00;
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
	int quit = 0;
	int i;
	int j;
	x = -WIDTH / 2 - 1;
	while (++x < WIDTH / 2)
	{
		y = -HEIGHT / 2 - 1;
		while (++y < HEIGHT / 2)
		{
			CanvasToViewport(rtv1, x, -y);
//				((int *)surface->pixels)[(x + WIDTH / 2 + (y + HEIGHT / 2) * WIDTH)] = 0xFF;
			((int *)surface->pixels)[(x + WIDTH / 2 + (y + HEIGHT / 2) * WIDTH)] = TraceRay(rtv1, 1, 100000);
		}
	}
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
	while (!quit) {
		SDL_WaitEvent(&event);
		if (event.type == SDL_QUIT) {
			quit = 1;
		}
		if (event.type == SDL_KEYDOWN)
		{
//			if (event.key.keysym.sym == SDLK_DOWN)
//			{
//				for (x = 0; x < WIDTH; ++x)
//					for (y = 0; y < HEIGHT; ++y) {
//						SDL_SetRenderDrawColor(renderer, x, y, x, 255);
//						SDL_RenderDrawPoint(renderer, x, y);
//					}
//				x = -HEIGHT / 2 - 1;
//				while (++x < HEIGHT / 2)
//				{
//					y = -HEIGHT / 2 - 1;
//					while (++y < HEIGHT / 2)
//					{
//						CanvasToViewport(rtv1, x, y);
//						TraceRay(rtv1, 0, 1, t, d);
//						SDL_RenderDrawPoint(renderer, x, y);
//						if (t == d)
//							SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
//						else
//							SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
//						SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
//					}
//				}
//				SDL_RenderPresent(renderer);
//			}
//			if (event.key.keysym.sym == SDLK_1)
//			{
//				i = -1;
//				j = -1;
//				while (++i < WIDTH)
//				{
//					while (++j < HEIGHT)
//					{
//						SDL_RenderDrawPoint(renderer, i, j);
//					}
//				}
//				SDL_RenderDrawPoint(renderer, i, i);
//			}
//			if (event.key.keysym.sym == SDLK_f)
//			{
//                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
//                SDL_RenderClear(renderer);
//				SDL_RenderPresent(renderer);
//			}
			if (event.key.keysym.sym == SDLK_ESCAPE)
				quit = 1;
		}
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return EXIT_SUCCESS;
}

