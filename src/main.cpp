#include <cstdlib>
#include <cstdio>
#include <config.h>
#include <SDL.h>
#include <SDL_gfxPrimitives.h>
int main(int argc, char *argv[])
{

    SDL_Surface *ecran = NULL, *texte = NULL, *fond = NULL;
    SDL_Rect position;
    SDL_Event event;
    TTF_Font *police = NULL;
    bool continuer = 1;


    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Simple test"), NULL);

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

        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));

    }
    SDL_Quit();
    return EXIT_SUCCESS;
}
