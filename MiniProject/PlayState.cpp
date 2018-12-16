#include "PlayState.h"
#include "TextureManager.h"
#include "Player.h"
#include "Background.h"
#include "Barrier.h"
#include "HitBox.h"
#include "Game.h"
#include"InputHandler.h"
#include"GameOverState.h"
#include"CollisionManager.h"
#include<SDL_ttf.h>
#include<time.h>

#define PLAYER 0
#define FIRE 1
#define HITBOX 2
#define OUT_COLLIDER 3
#define ENEMY 4
const std::string PlayState::s_playID = "PLAY";
CollisionManager* TheCollisionManager::s_pInstance = 0;
void PlayState::Update()
{
	//플레이어 히트박스와 적(장애물) 충돌시
	for (int i = ENEMY; i < m_gameObjects.size(); i+=2)
	{
		if (CollisionManager::Instance()->checkCollision(
			dynamic_cast<SDLGameObject*> (m_gameObjects[HITBOX]),
			dynamic_cast<SDLGameObject*>(m_gameObjects[i])))
		{
  			TheGame::Instance()->getStateMachine()->changeState(
				new GameOverState());
		}
/*
		if (TheProjectileManager::Instance()->onHit(m_gameObjects[i]))
		{
			m_gameObjects.erase(m_gameObjects.begin() + i);
		}
*/
	}

	//플레이어와 적 히트박스 충돌시
	for (int i = ENEMY + 1; i < m_gameObjects.size(); i += 2)
	{
		if (CollisionManager::Instance()->checkCollision(
			dynamic_cast<SDLGameObject*> (m_SDLObjects[PLAYER]),
			dynamic_cast<SDLGameObject*>(m_gameObjects[i])) && scoreCheck1 && scoreCheck2)
		{
			score++;
			scoreCheck1 = false;
			scoreCheck2 = false;
		}
	}

	if (TheInputHandler::Instance()->isKeyDown(
		SDL_SCANCODE_SPACE))
	{
		scoreCheck1 = true;
	}
		
	////esc키 누를시 pauseState전환
	//if (TheInputHandler::Instance()->isKeyDown(
	//	SDL_SCANCODE_ESCAPE))
	//{
	//	TheGame::Instance()->getStateMachine()->changeState(
	//		new PauseState());
	//}

	//플레이어 발사체 발사
	/*if (TheInputHandler::Instance()->getMouseButtonState(LEFT) && shotCooltime >= 10)
	{
		TheProjectileManager::Instance()->Shot(m_gameObjects[PLAYER]->getPosition().getX() + 50,
			m_gameObjects[PLAYER]->getPosition().getY()+40, 10, m_gameObjects[PLAYER]->getVelocity().getX());
		shotCooltime = 0;
		
	}*/

	//적 랜덤한 시간에 스폰
	if(spawnCooltime >= getRandomSpawnTime())
	{
		GameObject* barriers = new Barrier(
			new LoaderParams(1320, 300, 64, 86, "barrier"));
		GameObject* e_hitBox = new Barrier(//적 히트박스(점수체크용)
			new LoaderParams(1360, 250, 20, 100, "scorecheck"));
		
		m_gameObjects.push_back(barriers);
		m_gameObjects.push_back(e_hitBox);
		spawnCooltime = 0;
	}

	shotCooltime++;
	spawnCooltime++;
	if (SDL_GetTicks() >= beginTick + 1000)
	{
		beginTick = SDL_GetTicks();
		playTime++;
		std::cout << "playTime is " << playTime << std::endl;
		scoreCheck2 = true;
	}
	//playTime = beginTick / 1000;
	//playTime = (SDL_GetTicks() - (SDL_GetTicks() * resetCount))/1000;

	for (int i = ENEMY; i < m_gameObjects.size(); i++)
	{
		if (CollisionManager::Instance()->checkCollision(
			dynamic_cast<SDLGameObject*>(m_gameObjects[OUT_COLLIDER]),
			dynamic_cast<SDLGameObject*>(m_gameObjects[i])))
		{
			m_gameObjects.erase(m_gameObjects.begin() + i);
			std::cout << "erase" << std::endl;
		}
	}
	if (playTime == 30)
	{
		m_SDLObjects[FIRE] = new Player(
			new LoaderParams(m_SDLObjects[PLAYER]->getX()-81, m_SDLObjects[PLAYER]->getY(), 81, 98, "fire"));
	}
	if (playTime == 60)
	{
		m_SDLObjects[PLAYER] = new Player(
			new LoaderParams(m_SDLObjects[FIRE]->getX() + 81, m_SDLObjects[FIRE]->getY(),
				81, 98, "playerfire"));
	}

//	m_SDLObjects[FIRE]->getPosition().setX(m_SDLObjects[PLAYER]->getX() - 81);
//	m_SDLObjects[FIRE]->getPosition().setY(m_SDLObjects[PLAYER]->getY() + 60);

	GameState::Update();


}
void PlayState::Render()
{
	GameState::Render();
	TextureManager::Instance()->DrawText("score_text", 10, 10,
		TheGame::Instance()->getRenderer());
	TextureManager::Instance()->UpdateAndDrawNumber(score, 100, 10,
		TheGame::Instance()->getRenderer());
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

	if (!TheTextureManager::Instance()->Load("assets/Stickmanfire.png",
		"playerfire", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->Load("assets/wall1.png",
		"barrier", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TextureManager::Instance()->LoadText("assets/NanumGothicExtraBold.ttf", 20,
		"SCORE: ", "score_text", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->Load("assets/fire.png",
		"fire", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	SDLGameObject* player = new Player(
		new LoaderParams(0, 260, 81, 98, "player"));
	SDLGameObject* fire = new SDLGameObject(new LoaderParams(-81, 260, 81, 39, "null"));
	GameObject* bg1 = new Background(
		new LoaderParams(0, 0, 640, 480, "background"));
	GameObject* bg2 = new Background(
		new LoaderParams(640, 0, 640, 480, "background"));
	GameObject* p_hitBox = new HitBox(
		new LoaderParams(15, 250, 50, 60, "hitbox"));
	GameObject* o_hitBox = new SDLGameObject(
		new LoaderParams(-80, 300, 16, 100, "out"));
	m_gameObjects.push_back(bg1);
	m_gameObjects.push_back(bg2);
	m_gameObjects.push_back(p_hitBox);
	m_gameObjects.push_back(o_hitBox);
	m_SDLObjects.push_back(player);
	m_SDLObjects.push_back(fire);
	//m_gameObjects.push_back(enemy);
	std::cout << "entering PlayState\n";
	return true;

}

bool PlayState::onExit()
{

	if (!GameState::onExit())
		return false;

	TheTextureManager::Instance()->clearFromTextureMap("background");
	TheTextureManager::Instance()->clearFromTextureMap("player");
	TheTextureManager::Instance()->clearFromTextureMap("playerfire");
	TheTextureManager::Instance()->clearFromTextureMap("barrier");

	int i = 0; int j = 0;

	beginTick = 0;
	playTime = 0;
	resetCount++;
	std::cout << "exiting PlayState\n";

	return true;
	
}

int PlayState::getRandomSpawnTime()
{
	srand(time(NULL));
	int difficulty = (280 - playTime) + 1;
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

