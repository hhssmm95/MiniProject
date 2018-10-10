#include"Game.h"
#include<iostream>


Game* new_game = 0;

int main(int argc, char** argv)
{
	new_game = new Game();
	new_game->Init("GunShooter", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, 0);

	while (new_game->Running())
	{
		new_game->HandleEvents();
		new_game->Update();
		new_game->Render();
	}
	new_game->Clean();

	return 0;
}