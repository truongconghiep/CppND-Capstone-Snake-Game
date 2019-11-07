#include <SDL2/SDL.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include "StartWindow.h"

typedef struct
{
    SDL_Rect draw_rect; // dimensions of button
    struct
    {
        Uint8 r, g, b, a;
    } colour;

    bool pressed;
} button_t;

// button state - colour and rectangle
button_t EasyButton =
{
    {10, 40, 128, 50},
    {233, 245, 69, 255},
    false
};

// button state - colour and rectangle
button_t MediumButton =
{
    {140, 40, 128, 50},
    {209, 118, 194, 255},
    false
};

// button state - colour and rectangle
button_t HardButton =
{
    {270, 40, 128, 50},
    {213, 66, 76, 255},
    false
};

static void button_process_event(button_t *btn, const SDL_Event *ev)
{
    // react on mouse click within button rectangle by setting 'pressed'
    if (ev->type == SDL_MOUSEBUTTONDOWN)
    {
        if (ev->button.button == SDL_BUTTON_LEFT &&
            ev->button.x >= btn->draw_rect.x &&
            ev->button.x <= (btn->draw_rect.x + btn->draw_rect.w) &&
            ev->button.y >= btn->draw_rect.y &&
            ev->button.y <= (btn->draw_rect.y + btn->draw_rect.h))
        {
            btn->pressed = true;
        }
    }
}

static bool button(SDL_Renderer *r, button_t *btn)
{
    // draw button
    SDL_SetRenderDrawColor(r, btn->colour.r, btn->colour.g, btn->colour.b, btn->colour.a);
    SDL_RenderFillRect(r, &btn->draw_rect);

    // if button press detected - reset it so it wouldn't trigger twice
    if (btn->pressed)
    {
        btn->pressed = false;
        return true;
    }
    return false;
}

/*
- x, y: upper left corner.
- texture, rect: outputs.
*/
void get_text_and_rect(SDL_Renderer *renderer, int x, int y, char *text,
                       TTF_Font *font, SDL_Texture **texture, SDL_Rect *rect)
{
    int text_width;
    int text_height;
    SDL_Surface *surface;
    SDL_Color textColor = {60, 236, 224, 0};

    surface = TTF_RenderText_Solid(font, text, textColor);
    *texture = SDL_CreateTextureFromSurface(renderer, surface);
    text_width = surface->w;
    text_height = surface->h;
    SDL_FreeSurface(surface);
    rect->x = x;
    rect->y = y;
    rect->w = text_width;
    rect->h = text_height;
}

float StartWindow()
{
    SDL_Rect rect1, rect2, rect3, rect4;
    SDL_Texture *texture1, *texture2, *texture3, *texture4;
    char *font_path;

    font_path = (char *)"../FreeSans.ttf";

    int quit = 0;
    float RetVal = 0.2;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = NULL;
    window = SDL_CreateWindow("", 350, 150, 410, 120, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        fprintf(stderr, "create window failed: %s\n", SDL_GetError());
        return 1; // 'error' return status is !0. 1 is good enough
    }

    SDL_Renderer *renderer = NULL;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    { // renderer creation may fail too
        fprintf(stderr, "create renderer failed: %s\n", SDL_GetError());
        return 1;
    }

    TTF_Init();
    TTF_Font *font = TTF_OpenFont(font_path, 24);
    if (font == NULL)
    {
        fprintf(stderr, "error: font not found\n");
        exit(EXIT_FAILURE);
    }

    while (!quit)
    {
        SDL_Event evt; // no need for new/delete, stack is fine

        // event loop and draw loop are separate things, don't mix them
        while (SDL_PollEvent(&evt))
        {
            // quit on close, window close, or 'escape' key hit
            if (evt.type == SDL_QUIT ||
                (evt.type == SDL_WINDOWEVENT && evt.window.event == SDL_WINDOWEVENT_CLOSE) ||
                (evt.type == SDL_KEYDOWN && evt.key.keysym.sym == SDLK_ESCAPE))
            {
                quit = 1;
            }

            // pass event to button
            button_process_event(&EasyButton, &evt);
            button_process_event(&MediumButton, &evt);
            button_process_event(&HardButton, &evt);
        }

        if (button(renderer, &EasyButton))
        {
            RetVal = 0.02;
            break;
        }
        if (button(renderer, &MediumButton))
        {
            RetVal = 0.4;
            break;
        }
        if (button(renderer, &HardButton))
        {
            RetVal = 0.06;
            break;
        }

        get_text_and_rect(renderer, 65, 5, (char *)"Please choose play mode", font, &texture1, &rect1);
        get_text_and_rect(renderer, 45, 50, (char *)"Easy           Medium           Hard", font, &texture2, &rect2);

            /* Use TTF textures. */
        SDL_RenderCopy(renderer, texture1, NULL, &rect1);
        SDL_RenderCopy(renderer, texture2, NULL, &rect2);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

        SDL_RenderPresent(renderer);
    }

    /* Deinit TTF. */
    SDL_DestroyTexture(texture1);
    SDL_DestroyTexture(texture2);
    TTF_Quit();

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    return RetVal;
}
