#include "MenuState.h"
#include "TextureManager.h"
#include "Game.h"
#include "MenuButton.h"
#include "PlayState.h"

const std::string MenuState::s_menuID = "MENU";

void MenuState::Update()
{
	GameState::Update();
}

void MenuState::Render()
{
	GameState::Render();
}

bool MenuState::onEnter()
{
	if (!TheTextureManager::Instance()->Load("assets/run.png",
		"runbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->Load("assets/exit2.png",
		"exitbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->Load("assets/title1.png",
		"title", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	GameObject* button1 = new MenuButton(
		new LoaderParams(140, 200, 343, 105, "runbutton"),
		s_menuToPlay);

	GameObject* button2 = new MenuButton(
		new LoaderParams(140, 340, 343, 105, "exitbutton"),
		s_exitFromMenu);
	GameObject* title = new SDLGameObject(
		new LoaderParams(0, 0, 640, 480, "title"));
	m_gameObjects.push_back(title);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	
	std::cout << "entering MenuState\n";
	return true;

}

bool MenuState::onExit()
{
	if (!GameState::onExit())
		return false;
	TheTextureManager::Instance()
		->clearFromTextureMap("playbutton");
	TheTextureManager::Instance()
		->clearFromTextureMap("exitbutton");
	TheTextureManager::Instance()
		->clearFromTextureMap("background");
	std::cout << "exiting MenuState\n";
	return true;

}
void MenuState::s_menuToPlay()
{
	TheGame::Instance()->getStateMachine()->changeState(
		PlayState::Instance());

}

void MenuState::s_exitFromMenu()
{
	TheGame::Instance()->quit();
}
