#include<SDL.h>

class Game
{
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Rect player_sRect;
	SDL_Rect player_dRect;
	SDL_Texture* texture1;
	bool isRunning;

public:
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