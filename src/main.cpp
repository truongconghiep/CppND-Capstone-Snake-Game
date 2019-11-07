#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm> // std::find_if
#include "StartWindow.h"

using namespace std;

bool is_number(const std::string &s)
{
  return !s.empty() && std::find_if(s.begin(),
                                    s.end(), [](char c) { return !std::isdigit(c); }) == s.end();
}

void MainGame()
{
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  Game *game = new Game(kGridWidth, kGridHeight);

  float Difficulty = StartWindow();
  game->SetDifficulty(Difficulty);

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;

  /* Read record*/
  std::fstream stream;
  stream.open("Record.txt", std::fstream::in | std::fstream::out | std::fstream::app);
  string Record;
  stream >> Record;
  if (is_number(Record))
  {
    game->Record = stoi(Record);
  }
  else
  {
    game->Record = 0;
  }
  cout << "read record " << game->Record << endl;
  stream.close();

  game->Run(controller, renderer, kMsPerFrame);

  if (game->GameOver)
  {
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,
                             "",
                             "Game over - click ok to close",
                             NULL);
  }
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game->GetScore() << "\n";
  std::cout << "Size: " << game->GetSize() << "\n";

  /* Store record */
  std::fstream fs;
  fs.open("Record.txt", std::fstream::in | std::fstream::out | std::fstream::trunc);
  fs << to_string(game->Record);
  fs.close();

  delete game;
}

int main()
{
  MainGame();
  return 0;
}