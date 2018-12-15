#pragma once
#include"SDLGameObject.h"
#include <SDL.h>
#include<vector>
class ProjectileManager
{
private:
	void handleInput();
	std::vector<GameObject*> bullets;
	ProjectileManager();
	~ProjectileManager();
	static ProjectileManager* s_pInstance;
public:
	static ProjectileManager* Instance()
	{
		if (s_pInstance == 0) {
			s_pInstance = new ProjectileManager();
		}
		return s_pInstance;
	}
	void Shot(int x, int y, int velocity, int p_velocity);
	void render();
	bool onHit(GameObject* obj);
	void onOut();
	void update();
	void clean();
	//virtual SDL_Rect getCollider();
};
typedef ProjectileManager TheProjectileManager;