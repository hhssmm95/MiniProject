#pragma once
#include "SDLGameObject.h"

class CollisionManager
{
private:
	CollisionManager(){}
	~CollisionManager(){}
	static CollisionManager* s_pInstance;

public:
	static CollisionManager* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new CollisionManager();
			return s_pInstance;
		}
		return s_pInstance;
	}

	bool checkCollision(SDLGameObject* p1, SDLGameObject* p2);
	void Update();

};
typedef CollisionManager TheCollisionManager;