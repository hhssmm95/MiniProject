#include"Game.h"
#include"TextureManager.h"
#include"Background.h"
#include "InputHandler.h"
#include<iostream>
using namespace std;

InputHandler* InputHandler::s_pInstance = 0;

bool Game::Init(const char* title, int xpos, int ypos,
	int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		window = SDL_CreateWindow(title, xpos, ypos,
			width, height, fullscreen);

		renderer = SDL_CreateRenderer(window, -1, 0);

		isRunning = true;

		//플레이어 및 배경 텍스쳐 로드
		TheTextureManager::Instance()->load("assets/animate-alpha.png", "Player", renderer);
		TheTextureManager::Instance()->load("assets/background2.png", "Background", renderer);

		
		m_gameObjects.push_back(new Background(new LoaderParams(0, 0, 1280, 720, "Background")));
		m_gameObjects.push_back(new Background(new LoaderParams(1280, 0, 1280, 720, "Background")));
		m_gameObjects.push_back(new Player(new LoaderParams(0, 430, 128, 128, "Player")));
		//tempY = player_dRect.y;

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
	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
	SDL_RenderPresent(renderer);
}

void Game::Update()
{
	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}

	
}

void Game::Clean()
{
	std::cout << "cleaning game\n";
	TheInputHandler::Instance()->clean();
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

void Game::HandleEvents()
{
	TheInputHandler::Instance()->update();
}

void Game::quit()
{
	Clean();
}
