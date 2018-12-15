#include"Game.h"
#include<iostream>


Game* Game::s_pInstance = 0;

int main(int argc, char** argv)
{
	TheGame::Instance()->Init("Runner", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);

	const int FPS = 60;
	const int DELAY_TIME = 1000.0f / FPS;

	Uint32 frameStart, frameTime;


	std::cout << "game init success!\n";
	while (TheGame::Instance()->Running())
	{
		frameStart = SDL_GetTicks();
		TheGame::Instance()->HandleEvents();
		TheGame::Instance()->Render();
		TheGame::Instance()->Update();
		
		frameTime = SDL_GetTicks() - frameStart;

		if (frameTime < DELAY_TIME)
		{
			SDL_Delay((int)(DELAY_TIME - frameTime));
		}
	}
	std::cout << "game closing...\n";
	TheGame::Instance()->Clean();

	return 0;
}