#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  //   // Initialize SDL
  // if (SDL_Init(SDL_INIT_VIDEO) < 0) {
  //   std::cerr << "SDL could not initialize.\n";
  //   std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  // }


  // SDL_Window *sdl_window_start = SDL_CreateWindow("Start", SDL_WINDOWPOS_CENTERED - 100 ,
  //                                   SDL_WINDOWPOS_CENTERED - 100, 500,
  //                                   200 , SDL_WINDOW_SHOWN);

  // if (sdl_window_start == NULL) {
  //       // In the case that the window could not be made...
  //       std::cout << "Could not create window!\n";
  //       return 1;
  //   }

  // SDL_Renderer *sdl_renderer_start = SDL_CreateRenderer(sdl_window_start, -1, 0);

  // SDL_SetRenderDrawColor(sdl_renderer_start, 0,255,0,255);

  // //SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  // SDL_RenderClear(sdl_renderer_start);
  // SDL_RenderPresent(sdl_renderer_start);




  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight);
  game.Run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";

  // SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
  //                        "Missing file",
  //                        "File is missing. Please reinstall the program.",
  //                        NULL);
  return 0;
}