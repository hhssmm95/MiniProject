#include"Game.h"
#include"TextureManager.h"
#include"Background.h"
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

		//플레이어 및 배경 텍스쳐 로드
		TheTextureManager::Instance()->load("assets/animate-alpha.png", "Player", renderer);
		TheTextureManager::Instance()->load("assets/background1.png", "Background", renderer);

		m_gameObjects.push_back(new Player(new LoaderParams(0, 430, 128, 128, "Player")));
		m_gameObjects.push_back(new Background(new LoaderParams(0, 0, 1280, 720, "Background")));
		m_gameObjects.push_back(new Background(new LoaderParams(0, 1280, 1280, 720, "Background")));
		/*SDL_Surface* TempSurface = IMG_Load("assets/animate-alpha.png");
		SDL_Surface* bgTempSurface = IMG_Load("assets/background1.png");

		playerTexture = SDL_CreateTextureFromSurface(renderer, TempSurface);
		bgTexture1 = SDL_CreateTextureFromSurface(renderer, bgTempSurface);
		bgTexture2 = SDL_CreateTextureFromSurface(renderer, bgTempSurface);
		SDL_FreeSurface(TempSurface);
		SDL_FreeSurface(bgTempSurface);


		SDL_QueryTexture(playerTexture, NULL, NULL, &player_sRect.w, &player_sRect.h);
		SDL_QueryTexture(bgTexture1, NULL, NULL, &bg1_sRect.w, &bg1_sRect.h);
		SDL_QueryTexture(bgTexture2, NULL, NULL, &bg2_sRect.w, &bg2_sRect.h);*/
		//플레이어 위치, 크기 입력
		//player_sRect.w = 128; 
		//player_sRect.h = 128;
		//player_sRect.x = 0;
		//player_sRect.y = 0;

		//player_dRect.x = 0;
		//player_dRect.y = 430;
		//player_dRect.w = player_sRect.w;
		//player_dRect.h = player_sRect.h;

		////배경1 위치, 크기입력
		//bg1_sRect.w = bg1_dRect.w = 1280;
		//bg1_sRect.h = bg1_dRect.h = 720;
		//bg1_sRect.x = bg1_dRect.x = 0;
		//bg1_sRect.y = bg1_dRect.y = 0;

		////배걍2 위치, 크기입력
		//bg2_sRect.w = bg2_dRect.w = 1280;
		//bg2_sRect.h = bg2_dRect.h = 720;
		//bg2_sRect.x = 0;
		//bg2_dRect.x = 1280;
		//bg2_sRect.y = bg2_dRect.y = 0;
		
		tempY = player_dRect.y;

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
	SDL_RenderCopy(renderer, bgTexture1, &bg1_sRect, &bg1_dRect);
	SDL_RenderCopy(renderer, bgTexture2, &bg2_sRect, &bg2_dRect);
	SDL_RenderCopy(renderer, playerTexture, &player_sRect, &player_dRect);
	SDL_RenderPresent(renderer);
}

void Game::Update()
{
	//배경 무한스크롤
	player_sRect.x = 128 * int(((SDL_GetTicks() / 100) % 6));
	if (bg1_dRect.x > -1280)
	{
		SDL_Delay(5);
		bg1_dRect.x--;
	}
	else
		bg1_dRect.x = 0;

	if (bg2_dRect.x > 0)
	{
		SDL_Delay(5);
		bg2_dRect.x--;
	}
	else
		bg2_dRect.x = 1280;

	//점프 활성화시
	if (isJumping)
	{
		
		if (!isTop && player_dRect.y > tempY - 60)
		{
			player_dRect.y -= 2;
		}
		else if (!isTop && player_dRect.y <= tempY - 60)
		{
			isTop = true;
		}

		if (isTop && player_dRect.y < tempY)
		{
			player_dRect.y += 3;
		}
		else if (isTop&& player_dRect.y == tempY)
		{
			isJumping = false;
			isTop = false;
		}
	}
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
			case SDLK_SPACE:
				//스페이스 입력시 점프
				isJumping = true;	

			default:
				break;
			}
		default:
			break;
		}
	}
}
