#include<SDL.h>
#include"Player.h"
#include"GameStateMachine.h" 
#include<vector>
class Game
{
private:
	static Game* s_pInstance;

	int m_currentFrame;

	Game() {}
	~Game() {}
	SDL_Window* window;
	SDL_Renderer* renderer;

	bool isRunning;
	GameStateMachine* m_pGameStateMachine;



public:
	SDL_Renderer * getRenderer() const { return renderer; }
	GameStateMachine* getStateMachine() { return m_pGameStateMachine; }

	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}

	void quit();

	bool Init(const char* title, int xpos, int ypos,
		int width, int height, bool fullscreen);
	void Render();
	void Update();
	void HandleEvents();
	void Clean();
	bool Running() {
		return isRunning;
	}
	void Quit();

};
typedef Game TheGame;