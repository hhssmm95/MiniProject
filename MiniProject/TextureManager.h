#pragma once
#include<map>
#include<SDL.h>
class TextureManager
{
private:

	std::map<std::string, SDL_Texture*>m_textureMap;

	TextureManager() {}
	~TextureManager() {}
public:

	bool Load(std::string fileName, std::string id, SDL_Renderer* pRenderer);
	void Draw(std::string id, int x, int y, int width, int height,
		SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void drawFrame(std::string id, int x, int y, int width, int height,
		int currentRow, int currentFrame,
		SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void clearFromTextureMap(std::string id);

	bool LoadText(const char* fontName, int size, const char* message, std::string id, SDL_Renderer* pRenderer);
	//bool LoadText(const char* fontName, int size, std::string message, std::string id, SDL_Renderer* pRenderer);
	void DrawText(std::string id, int x, int y, SDL_Renderer* pRenderer);
	bool UpdateAndDrawNumber(int score, int x, int y, SDL_Renderer* pRenderer);
	static TextureManager* Instance()
	{
		static TextureManager* s_pInstance;

		if (s_pInstance == 0)
		{
			s_pInstance = new TextureManager();
			return s_pInstance;
		}
		return s_pInstance;
	}



};

typedef TextureManager TheTextureManager;