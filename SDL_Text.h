#include <SDL.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <string>
#include "RendererEngine.h"
#pragma once
class SDL_Text
{
public:
	bool init();
	bool createTexturefromText(RendererEngine* renderer, std::string score);
	void renderText(RendererEngine* renderer, int screenWidth, int screenHeight);
	void close();
private:
	TTF_Font* m_Font = NULL;
	const char* M_MY_FONT = "C:/Windows/Fonts/Candara.ttf";
	SDL_Texture* m_textureOfText = NULL;
	SDL_Surface* m_surfaceOfText = NULL;
	bool createSurfaceFromText(std::string score);
};

