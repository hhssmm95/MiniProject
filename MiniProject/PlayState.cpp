#include "PlayState.h"
#include "TextureManager.h"
#include "Player.h"
#include "Enemy.h"
#include "Background.h"
#include "Barrier.h"
#include "HitBox.h"
#include "Game.h"
#include"InputHandler.h"
#include"PauseState.h"
#include"GameOverState.h"
#include"CollisionManager.h"
#include "ProjectileManager.h"
#include<time.h>

#define PLAYER 2
#define HITBOX 3
#define ENEMY 4
const std::string PlayState::s_playID = "PLAY";
CollisionManager* TheCollisionManager::s_pInstance = 0;
ProjectileManager* TheProjectileManager::s_pInstance = 0;
void PlayState::Update()
{
	for (int i = ENEMY; i < m_gameObjects.size(); i++)
	{
		if (CollisionManager::Instance()->checkCollision(
			dynamic_cast<SDLGameObject*> (m_gameObjects[HITBOX]),
			dynamic_cast<SDLGameObject*>(m_gameObjects[i])))
		{
			TheGame::Instance()->getStateMachine()->changeState(
				new GameOverState());
		}
	}
		
	
	if (TheInputHandler::Instance()->isKeyDown(
		SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->getStateMachine()->changeState(
			new PauseState());
	}

	if (TheInputHandler::Instance()->getMouseButtonState(LEFT) && shotCooltime >= 10)
	{
		TheProjectileManager::Instance()->Shot(m_gameObjects[PLAYER]->getPosition().getX() + 50,
			m_gameObjects[PLAYER]->getPosition().getY()+40, 10, m_gameObjects[PLAYER]->getVelocity().getX());
		shotCooltime = 0;
		
	}

	for (int i = ENEMY; i < m_gameObjects.size(); i++)
	{
		if (TheProjectileManager::Instance()->onHit(m_gameObjects[i]))
		{
			m_gameObjects.erase(m_gameObjects.begin() + i);
		}
	}
	

	if(spawnCooltime >= getRandomSpawnTime())
	{
		GameObject* barriers = new Barrier(
			new LoaderParams(1320, 300, 64, 86, "barrier"));
		m_gameObjects.push_back(barriers);
		spawnCooltime = 0;
	}
	TheProjectileManager::Instance()->update();
	GameState::Update();

	shotCooltime++;
	spawnCooltime++;
	playTime = SDL_GetTicks() / 1000;
}
void PlayState::Render()
{
	GameState::Render();
	TheProjectileManager::Instance()->render();
}
bool PlayState::onEnter()
{
	if (!TheTextureManager::Instance()->Load("assets/background1.png",
		"background", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->Load("assets/Stickman.png",
		"player", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->Load("assets/wall1.png",
		"barrier", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	GameObject* player = new Player(
		new LoaderParams(0, 260, 81, 98, "player"));
	GameObject* bg1 = new Background(
		new LoaderParams(0, 0, 640, 480, "background"));
	GameObject* bg2 = new Background(
		new LoaderParams(640, 0, 640, 480, "background"));
	GameObject* p_hitBox = new HitBox(
		new LoaderParams(15, 250, 50, 60, "hitbox"));
	
	m_gameObjects.push_back(bg1);
	m_gameObjects.push_back(bg2);
	m_gameObjects.push_back(player);
	m_gameObjects.push_back(p_hitBox);
	//m_gameObjects.push_back(enemy);
	std::cout << "entering PlayState\n";
	return true;

}

bool PlayState::onExit()
{
	if (!GameState::onExit())
		return false;
	TheTextureManager::Instance()->clearFromTextureMap("background");
	playTime = 0;
	std::cout << "exiting PlayState\n";
	return true;

}

int PlayState::getRandomSpawnTime()
{
	srand(time(NULL));
	int difficulty = (500 - playTime) + 1;
	std::cout << "playTime is " << playTime << std::endl;
	if (difficulty < 80)
		difficulty = 81;
	int y;
	for(int i = 0; i<3; i++)
		y = rand()%difficulty + 40;
	return y;
}

int PlayState::getplayTime()
{
	return playTime;
}

