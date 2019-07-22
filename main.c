//
// Created by Calista Fahey on 2019-07-17.
//

#include "rtv1.h"
//
//SDL_Window *gWindow = NULL;
//SDL_Surface *gScreenSurface = NULL;
//SDL_Surface *gHelloWorld = NULL;
//SDL_Renderer *gRenderer;
//
//int 	init()
//{
//	int success = 1;
//
//	if (SDL_Init(SDL_INIT_VIDEO) < 0)
//	{
//		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
//		success = 0;
//	}
//	else
//	{
//		gWindow = SDL_CreateWindow("SDL Tutorial",  SDL_WINDOWPOS_UNDEFINED,
//								   SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
//		if (gWindow == NULL)
//		{
//			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
//			success = 0;
//		}
//		else
//		{
//			gScreenSurface = SDL_GetWindowSurface(gWindow);
//		}
//	}
//	return (success);
//}
//
//int 	loadMedia(SDL_Surface *surface)
//{
//	int 	success = 1;
//
//	if (gHelloWorld == NULL)
//	{
//		printf( "Unable to load image %s! SDL Error: %s\n",
//				"SDL/hello_world.bmp", SDL_GetError() );
//		success = 0;
//	}
//	return (success);
//}
//
//void	close()
//{
//	SDL_FreeSurface(gHelloWorld);
//	gHelloWorld = NULL;
//
//	SDL_DestroyWindow(gWindow);
//	gWindow = NULL;
//
//	SDL_Quit();
//}
//
//int 	main()
//{
////	int 	quit = 0;
//////
//////	SDL_Event e;
//////	SDL_KeyboardEvent key;
//////
//////	if(!init())
//////	{
//////		printf( "Failed to initialize!\n" );
//////	}
//////	else
//////	{
//////		if (!loadMedia(gHelloWorld = SDL_LoadBMP("/Users/cfahey/CLionProjects//SDL/hello_world.bmp")))
//////		{
//////			printf( "Failed to load media!\n" );
//////		}
//////		else
//////		{
//////			while (!quit)
//////			{
//////				SDL_WaitEvent(&e);
//////				if (e.type == SDL_QUIT) {
//////					quit = 1;
//////				}
////////				if (e.type == SDL_KEYDOWN) {
////////					if (e.key.keysym.sym == SDLK_ESCAPE)
////////						quit = 1;
////////					if (e.key.keysym.sym == SDLK_UP) {
////////
////////						SDL_DestroyWindow(gWindow);
////////						gWindow = NULL;
////////
////////						init();
////////
////////						if (!loadMedia(gHelloWorld = SDL_LoadBMP(
////////								"/Users/cfahey/CLionProjects//SDL/image.bmp"))) {
////////							printf("Failed to load media!\n");
////////						}
////////					}
////////
////////					if (e.key.keysym.sym == SDLK_DOWN) {
////////
////////						SDL_DestroyWindow(gWindow);
////////						gWindow = NULL;
////////
////////						init();
////////
////////						if (!loadMedia(gHelloWorld = SDL_LoadBMP(
////////								"/Users/cfahey/CLionProjects//SDL/hello_world.bmp"))) {
////////							printf("Failed to load media!\n");
////////						}
////////					}
////////					if (e.key.keysym.sym == SDLK_f)
////////					{
////////						SDL_DestroyWindow(gWindow);
////////						gWindow = NULL;
////////						int i = 0;
////////
////////						init();
////////
////////						SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0);
////////						SDL_RenderClear(gRenderer);
////////						SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, 255);
////////						for (i = 0; i < WIDTH; ++i)
////////							SDL_RenderDrawPoint(gRenderer, i, i);
////////						SDL_RenderPresent(gRenderer);
////////					}
////////				}
////////
////////				SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);
////////				SDL_UpdateWindowSurface(gWindow);
//////			}
////////			SDL_DestroyWindow(gWindow);
////////			gWindow = NULL;
////////
////////			init();
//////
//////			int i = 0;
//////			SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0);
//////			SDL_RenderClear(gRenderer);
//////			SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, 255);
//////			for (i = 0; i < WIDTH; ++i)
//////				SDL_RenderDrawPoint(gRenderer, i, i);
//////			SDL_RenderPresent(gRenderer);
//////		}
//////	}
//////
//////
//////	close();
//////
//////	return 0;
//
//	SDL_Event event;
//	SDL_Renderer *renderer;
//	SDL_Window *window;
//	int i;
//
//	SDL_Init(SDL_INIT_VIDEO);
//	SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer);
//	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
//	SDL_RenderClear(renderer);
//	int quit = 0;
//	while (!quit) {
//		SDL_WaitEvent(&event);
//		if (event.type == SDL_QUIT) {
//			quit = 1;
//		}
//		if (event.type == SDL_KEYDOWN)
//		{
//			if (event.key.keysym.sym == SDLK_DOWN)
//			{
//
//				for (i = 0; i < WIDTH; ++i)
//					for (int j = 0; j < HEIGHT; ++j) {
//						SDL_SetRenderDrawColor(renderer, i, j, i, 255);
//						SDL_RenderDrawPoint(renderer, i, j);
//					}
//			}
//			if (event.key.keysym.sym == SDLK_f)
//			{
//				SDL_RenderPresent(renderer);
//			}
//			if (event.key.keysym.sym == SDLK_ESCAPE)
//				quit = 1;
//		}
//	}
//	SDL_DestroyRenderer(renderer);
//	SDL_DestroyWindow(window);
//	SDL_Quit();
//	return EXIT_SUCCESS;
//}
