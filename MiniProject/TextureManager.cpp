#include"TextureManager.h"
#include<SDL_image.h>
#include<SDL_ttf.h>

bool TextureManager::Load(std::string fileName, std::string id,
	SDL_Renderer* pRenderer)
{
	SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());
	if (pTempSurface == 0) {
		return false;
	}

	SDL_Texture* pTexture =
		SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
	SDL_FreeSurface(pTempSurface);

	if (pTexture != 0) {
		m_textureMap[id] = pTexture;
		return true;
	}

	return false;

}

bool TextureManager::LoadText(const char* fontName, int size, const char* message, std::string id, SDL_Renderer* pRenderer)
{
	TTF_Font* font;
	font = TTF_OpenFont(fontName, size);
	if (font == NULL)
		return false;

	SDL_Color color;
	color.r = 255;
	color.g = 255;
	color.b = 255;

	SDL_Surface* pSurface;
	pSurface = TTF_RenderText_Solid(font, message, color);
	SDL_Texture* text = SDL_CreateTextureFromSurface(pRenderer, pSurface);

	if (text != 0) {
		m_textureMap[id] = text;
		return true;
	}
	return false;

}

void TextureManager::DrawText(std::string id, int x, int y, SDL_Renderer* pRenderer)
{

	SDL_Rect textRect;

	int w = 0;
	int h = 0;

	SDL_QueryTexture(m_textureMap[id], NULL, NULL, &w, &h);
	textRect.x = 0;
	textRect.y = 0;
	textRect.w = w;
	textRect.h = h;

	SDL_RenderCopy(pRenderer, m_textureMap[id], NULL, &textRect);
}


void TextureManager::Draw(std::string id,
	int x, int y, int width, int height,
	SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(pRenderer, m_textureMap[id],
		&srcRect, &destRect, 0, 0, flip);
}

void TextureManager::drawFrame(std::string id, int x, int y,
	int width, int height, int currentRow, int currentFrame,
	SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = width * currentFrame;
	srcRect.y = height * (currentRow - 1);
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect,
		&destRect, 0, 0, flip);
}
void TextureManager::clearFromTextureMap(std::string id)
{
	m_textureMap.erase(id);
}