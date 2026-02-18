#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>

#define WIDTH 1200
#define HEIGHT 800

int main(int argc, char *argv[])
{
    // 初始化
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        SDL_Log("Init failed: %s", SDL_GetError());
        return -1;
    }

    // 创建窗口
    SDL_Window *win = SDL_CreateWindow(
        "HelloSDL",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WIDTH,
        HEIGHT,
        SDL_WINDOW_SHOWN);

    if (NULL == win)
    {
        SDL_Log("SDL_CreateWindows failed: %s", SDL_GetError());
        return -1;
    }

    // 获取Surface
    SDL_Surface *Surface = SDL_GetWindowSurface(win);
    if (Surface == NULL)
    {
        SDL_Log("SDL_GetWindowSurface failed: %s", SDL_GetError());
        return -1;
    }

    int rect_w = 100, rect_h = 100;
    // 定义矩形
    SDL_Rect rects[4] = {
        {0, 0, rect_w, rect_h},
        {0, HEIGHT - rect_h, rect_w, rect_h},
        {WIDTH - rect_w, 0, rect_w, rect_h},
        {WIDTH - rect_w, HEIGHT - rect_h, rect_w, rect_h},
    };
    
    // // 在Surface 中绘制
    // SDL_FillRect(Surface, &rect, 0x00ff00);
    // // SDL_FillRect(Surface, &rect, SDL_MapRGB(Surface->format, 0, 255, 0));
    
    // // 将绘制的内容更新到屏幕上
    // SDL_UpdateWindowSurface(win);
     
    SDL_Event event;
    while (true)
    {
        if (SDL_PollEvent(&event))
        {
            printf("%u\n", event.type);
            if (event.type == SDL_QUIT)
            {
                break;
            }
        }

        SDL_FillRects(Surface, rects, 4, 0x00ff00);
        SDL_UpdateWindowSurface(win);
    }

    // 释放Surface
    SDL_FreeSurface(Surface);

    // 销毁窗口 
    SDL_DestroyWindow(win);

    // 退出 
    SDL_Quit();

    return 0;
}