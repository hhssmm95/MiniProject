#include "GameState.h"

void GameState::Update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->Update();
	}
	for (int i = 0; i < m_SDLObjects.size(); i++)
	{
		m_SDLObjects[i]->Update();
	}

}

void GameState::Render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->Draw();
	}
	for (int i = 0; i < m_SDLObjects.size(); i++)
	{
		m_SDLObjects[i]->Draw();
	}
}

bool GameState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->Clean();
	}
	for (int i = 0; i < m_SDLObjects.size(); i++)
	{
		m_SDLObjects[i]->Clean();
	}
	m_gameObjects.clear();
	m_SDLObjects.clear();
	return true;
}