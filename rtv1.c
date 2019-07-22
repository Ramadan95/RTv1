//
// Created by Calista Fahey on 2019-07-17.
//

#include "rtv1.h"

void		CanvasToViewport(t_rtv1 *rtv1, int x, int y)
{
	rtv1->d[0] = x * rtv1->Vw / WIDTH;
	rtv1->d[1] = y * rtv1->Vh / HEIGHT;
	rtv1->d[2] += 0.25;
}

int 	lenght(t_rtv1 *rtv1)
{

}

double	dot(const double v1[3], const double v2[3])
{
	return (v1[0]*v2[0] + v1[1]*v2[1] + v1[2]*v2[2]);
}

void	IntersectRaySphere(t_rtv1 *rtv1)
{
	double  c[3];
	double	r;
	double	oc[3];
	double	discriminant;

	c[0] = rtv1->sphere->center[0];
	c[1] = rtv1->sphere->center[1];
	c[2] = rtv1->sphere->center[2];
	r = rtv1->sphere->radius;
	oc[0] = rtv1->o[0] - c[0];
	oc[1] = rtv1->o[1] - c[1];
	oc[2] = rtv1->o[2] - c[2];

	rtv1->k1 = dot(rtv1->d, rtv1->d);
	rtv1->k2 = 2 * dot(oc, rtv1->d);
	rtv1->k3 = dot(oc, oc);

	discriminant = rtv1->k2 * rtv1->k2 - 4 * rtv1->k1 * rtv1->k3;
	if (discriminant < 0)
	{
		rtv1->t[0] = 0;
		rtv1->t[1] = 0;
	}
	rtv1->t[0] = (-rtv1->k2 + sqrt(discriminant) / (2 * rtv1->k1));
	rtv1->t[1] = (-rtv1->k2 - sqrt(discriminant) / (2 * rtv1->k1));
}

void	TraceRay(t_rtv1 *rtv1, int min, int max)
{
//	rtv1->t = 10000;
	int i;
}


void	init(t_rtv1 *rtv1)
{
	rtv1->v_size = 1;
	rtv1->p_plane = 1;
	rtv1->Vw = 1;
	rtv1->Vh = 1;
	rtv1->o[0] = 0;
	rtv1->o[1] = 0;
	rtv1->o[2] = 0;
}

int 	main()
{
	t_rtv1 *rtv1;

	rtv1 = malloc(sizeof(t_rtv1));
	SDL_Event event;
	SDL_Renderer *renderer;
	SDL_Window *window;
	int x;
	int y;
	init(rtv1);
	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer);
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
	SDL_RenderClear(renderer);
	int quit = 0;
	int i;
	int j;
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
//						rtv1->color = TraceRay(O, D, 1, inf);
//						canvas.PutPixel(x, y, color);
//					}
//				}
//			}
			if (event.key.keysym.sym == SDLK_1)
			{
				i = -1;
				j = -1;
				while (++i < WIDTH)
				{
					while (++j < HEIGHT)
					{
						SDL_RenderDrawPoint(renderer, i, j);
					}
				}
				SDL_RenderDrawPoint(renderer, i, i);
			}
			if (event.key.keysym.sym == SDLK_f)
			{
				SDL_RenderPresent(renderer);
			}
			if (event.key.keysym.sym == SDLK_ESCAPE)
				quit = 1;
		}
	}
	printf("3");
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return EXIT_SUCCESS;
}
