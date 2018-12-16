#pragma once
#include"LoaderParams.h"
#include"Vector2D.h"
class GameObject
{
public:
	virtual void Draw() = 0;
	virtual void Update() = 0;
	virtual void Clean() = 0;
	virtual Vector2D getPosition() = 0;
	virtual Vector2D getVelocity() = 0;
	virtual void setVelocity_X(int x) = 0;
	virtual void setVelocity_Y(int y) = 0;


protected:
	GameObject(const LoaderParams* pParams) {}
	virtual ~GameObject() {}
};

