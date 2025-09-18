#include <SDL.H>
#pragma once
class RendererEngine
{
public:
	void init(SDL_Renderer* windowRenderer);
	void drawBlock(int x, int y, int width, int height, int R, int G, int B, int A);
	void drawSquare(int x, int y, int width, int height, int R, int G, int B);
	void drawQuad(int x, int y, int width, int height, SDL_Texture* textureToApply);

	void clearScreen();

	void close();
	SDL_Renderer* getRenderer();
private:

	SDL_Renderer* m_renderer = NULL;

};

