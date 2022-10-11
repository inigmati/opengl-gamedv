//Using SDL and standard IO
#include<stdio.h>
#include<SDL2/SDL.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int agrc, char* args[])
{
    SDL_Window* window = NULL;
    SDL_Surface* screen_surface = NULL;

    if(SDL_Init(SDL_INIT_VIDEO)<0)
    {
        printf("SDL Could not initialise! SDL_Error: %s\n", SDL_GetError());
    }

    else
    {
        window = SDL_CreateWindow("First Game dev", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
        if(window==NULL)
        {
            printf("Windows could not be created! SDL_Error: %s\n", SDL_GetError());
        }
        else
        {
            screen_surface = SDL_GetWindowSurface(window);
            SDL_FillRect(screen_surface, NULL, SDL_MapRGB(screen_surface->format, 0xFF, 0xFF, 0xFF));
            SDL_UpdateWindowSurface(window);
            SDL_Delay(8000);
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}