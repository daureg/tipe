#include <cstdlib>
#include <cstdio>
#include <config.h>
#include <SDL.h>
#include <SDL_gfxPrimitives.h>
int main(int argc, char *argv[])
{

	SDL_Surface *ecran = NULL, *line = NULL;
	SDL_Event event;
	bool continuer = true;

	SDL_Init(SDL_INIT_VIDEO);

	ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	SDL_WM_SetCaption("Simple test", NULL);

	while (continuer)
	{
		SDL_WaitEvent(&event);
		switch (event.type)
		{
			case SDL_QUIT:
				continuer = 0;
				break;
			case SDL_KEYDOWN: /* Si appui d'une touche */
				continuer = 0;
				break;
		}

		SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
		aalineRGBA(ecran, 50, 30, 350, 200, 255, 0, 0,255);
		filledCircleRGBA(ecran, 400, 400, 4, 0,255,0,128);
		SDL_Flip(ecran);

	}
	SDL_Quit();
	return EXIT_SUCCESS;
}
