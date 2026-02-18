#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>

#define WIDTH 1200
#define HEIGHT 800

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_Log("SDL_Init failed: %s\n", SDL_GetError());
        return -1;
    }

    SDL_Window *Windows = SDL_CreateWindow(
        "Demo02",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WIDTH,
        HEIGHT,
        0);

    SDL_Surface *Surface = SDL_GetWindowSurface(Windows);
    if (Surface == NULL)
    {
        SDL_Log("SDL_GetWindowSurface failed: %s\n", SDL_GetError());
        return -1;
    }

    // 导入BMP图片
    SDL_Surface *BMPSurface = SDL_LoadBMP("hello.bmp");
    if (BMPSurface == NULL)
    {
        SDL_Log("SDL_LoadBMP failed: %s\n", SDL_GetError());
        return -1;
    }

    // 将图片Surface复制到窗口Surface上
    SDL_BlitSurface(BMPSurface, NULL, Surface, NULL);

    SDL_UpdateWindowSurface(Windows);

    SDL_Event event;
    while (true)
    {
        if (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                break;
            }
        }
    }

    SDL_FreeSurface(BMPSurface);

    SDL_FreeSurface(Surface);

    SDL_DestroyWindow(Windows);

    SDL_Quit();

    return 0;
}