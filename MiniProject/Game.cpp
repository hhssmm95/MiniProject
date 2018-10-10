#include"Game.h"
#include<SDL_image.h>
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

		SDL_Surface* TempSurface = IMG_Load("assets/standing1.png");
		
		texture1 = SDL_CreateTextureFromSurface(renderer, TempSurface);
		SDL_FreeSurface(TempSurface);

		player_sRect.w = 128;
		player_sRect.h = 128;
		player_sRect.x = 0;
		player_sRect.y = 0;

		player_dRect.x = 640-128;
		player_dRect.y = 360-128;
		player_dRect.w = player_sRect.w;
		player_dRect.h = player_sRect.h;

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	}
	else {
		return false;
	}

	return true;
}

void Game::Render()
{
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture1, &player_sRect, &player_dRect);
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

		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_RIGHT:
				player_dRect.x++;
				break;
			case SDLK_LEFT:
				player_dRect.x--;
				break;
			case SDLK_UP:
				player_dRect.y--;
				break;
			case SDLK_DOWN:
				player_dRect.y++;
				break;

			default:
				break;
			}
		default:
			break;
		}
	}
}