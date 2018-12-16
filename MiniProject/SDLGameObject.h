#pragma once
#include "GameObject.h"
#include "Vector2D.h"

class SDLGameObject : public GameObject
{
public:
	SDLGameObject(const LoaderParams* pParams);
	virtual void Draw();
	void staticDraw();
	virtual void Update();
	virtual void Clean();
	virtual Vector2D getPosition();
	virtual Vector2D getVelocity();
	virtual void setVelocity_X(int x);
	virtual void setVelocity_Y(int y);
	virtual int getX();
	virtual int getY();
	virtual int getWidth();
	virtual int getHeight();
	void setX(int x);
	void setY(int y);
protected:
	int m_width;
	int m_height;
	int m_currentRow;
	int m_currentFrame;
	std::string m_textureID;

	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;
};
