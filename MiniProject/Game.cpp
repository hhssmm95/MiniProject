#include"Game.h"
#include"TextureManager.h"
#include"Background.h"
#include "InputHandler.h"
#include "MenuState.h"
#include "PlayState.h"
#include <SDL_ttf.h>
using namespace std;

InputHandler* InputHandler::s_pInstance = 0;
MenuState* MenuState::s_pInstance = 0;
PlayState* PlayState::s_pInstance = 0;

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
	if (TTF_Init() == -1)
	{
		return false;
	}
	m_pGameStateMachine = new GameStateMachine();
	m_pGameStateMachine->changeState(MenuState::Instance());
	//TTF_Init();

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

	return true;
}

void Game::Render()
{
	SDL_RenderClear(renderer);
	m_pGameStateMachine->Render();

	SDL_RenderPresent(renderer);
}

void Game::Update()
{
	m_pGameStateMachine->Update();
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
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
	{
		m_pGameStateMachine->changeState(PlayState::Instance());
	}
}

void Game::quit()
{
	Clean();
	//TTF_Quit();
}
