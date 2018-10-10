#include"Game.h"
#include<iostream>
using namespace std;

bool Game::Init(const char* title, int xpos, int ypos,
	int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		window = SDL_CreateWindow(title, xpos, ypos,
			width, height, fullscreen);

		renderer = SDL_CreateRenderer(window, -1, 0);

		isRunning = true;
	}
	else {
		return false;
	}

	return true;
}

void Game::Render()
{
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

void Game::Update()
{

}

void Game::Clean()
{
	cout << "Cleaing the Game" << endl;
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

void Game::HandleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			isRunning = false;
			break;

		default:
			break;
		}
	}
}