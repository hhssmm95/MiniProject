#include "ProjectileManager.h"
#include"TextureManager.h"
#include"Game.h"
#include"PlayState.h"
#include"Vector2D.h"
#include"CollisionManager.h"
#include <SDL.h>


ProjectileManager::ProjectileManager()
{
	if (!TheTextureManager::Instance()->Load("assets/bullet1.png",
		"bullet1", TheGame::Instance()->getRenderer())) {
		std::cout<<"bullet1 load failure"<<std::endl;
	}
	if (!TheTextureManager::Instance()->Load("assets/bullet2.png",
		"bullet2", TheGame::Instance()->getRenderer())) {
		std::cout << "bullet2 load failure" <<std::endl;
	}

}

void ProjectileManager::Shot(int x, int y, int velocity, int p_velocity)
{
	GameObject* bullet;
	
	if (p_velocity >= 2)
	{
		bullet = new SDLGameObject(new LoaderParams(x, y, 8, 8, "bullet1"));

		bullet->setVelocity_X(velocity);
		bullet->setVelocity_Y(3);
	}
	else if (p_velocity <= -2)
	{
		bullet = new SDLGameObject(new LoaderParams(x, y, 8, 8, "bullet1"));

		bullet->setVelocity_X(velocity);
		bullet->setVelocity_Y(-3);
	}
	else
	{
		bullet = new SDLGameObject(new LoaderParams(x, y, 8, 8, "bullet1"));

		bullet->setVelocity_X(velocity);
	}
	bullets.push_back(bullet);
}

void ProjectileManager::render()
{
	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i]->Draw();
	}
}

void ProjectileManager::update()
{
	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i]->Update();
	}
}

bool ProjectileManager::onHit(GameObject* obj)
{
	bool hit = false;
	for (int i = 0; i < bullets.size(); i++)
	{
		if (TheCollisionManager::Instance()->checkCollision(dynamic_cast<SDLGameObject*>(obj), dynamic_cast<SDLGameObject*>(bullets[i])))
		{
			bullets.erase(bullets.begin() + i);
			hit = true;
		}
	}
	return hit;
}