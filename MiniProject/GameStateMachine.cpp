#include "GameStateMachine.h"


void GameStateMachine::popState()
{
	changeState(m_prevState);
}

void GameStateMachine::changeState(GameState *pState)
{
	if (pState != NULL)
	{
		if (m_currentState != NULL) {
			m_prevState = m_currentState;
			m_currentState->onExit();
		}
		m_currentState = pState;
		m_currentState->onEnter();
	}
}

void GameStateMachine::Update()
{
	if (m_currentState != NULL)
		m_currentState->Update();
}

void GameStateMachine::Render()
{
	if (m_currentState != NULL)
		m_currentState->Render();
}
