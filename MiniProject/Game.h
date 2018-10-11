#include<SDL.h>

class Game
{
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Rect player_sRect;
	SDL_Rect player_dRect;
	SDL_Rect bg1_sRect;
	SDL_Rect bg1_dRect;
	SDL_Rect bg2_sRect;
	SDL_Rect bg2_dRect;
	SDL_Texture* playerTexture;
	SDL_Texture* bgTexture1;
	SDL_Texture* bgTexture2;
	bool isRunning;
	


public:
	bool isJumping = false;
	bool isTop = false;
	int tempY;

	bool Init(const char* title, int xpos, int ypos,
		int width, int height, bool fullscreen);
	void Render();
	void Update();
	void HandleEvents();
	void Clean();
	bool Running() {
		return isRunning;
	}

};