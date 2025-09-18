#include "RendererEngine.h"

void RendererEngine::init(SDL_Renderer* windowRenderer)
{
	m_renderer = windowRenderer;
}

void RendererEngine::drawBlock(int x, int y, int width, int height, int R, int G, int B, int A)
{
	// The rectangle shape
	SDL_Rect fillRect{ x, y, width, height };
	// The color 
	SDL_SetRenderDrawColor(m_renderer, R, G, B, A);
	// Draw the block
	SDL_RenderFillRect(m_renderer, &fillRect);
}

void RendererEngine::drawSquare(int x, int y, int width, int height, int R, int G, int B)
{
	// SDL_Rect lineRectangle = { gridX, gridY, blockDim, blockDim };
	SDL_Rect squareOutline = { x, y, width, height };
	SDL_SetRenderDrawColor(m_renderer, 0x00, 0x00, 0x00, 0x00);
	SDL_RenderDrawRect(m_renderer, &squareOutline);
}

void RendererEngine::drawQuad(int x, int y, int width, int height, SDL_Texture* textureToApply)
{
	SDL_Rect textRect = { x, y, width, height }; // rectangle where the text is drawn 
	SDL_RenderCopy(m_renderer, textureToApply, NULL, &textRect);
}

void RendererEngine::clearScreen()
{
	// clear the screen
	SDL_SetRenderDrawColor(m_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(m_renderer);
}

void RendererEngine::close()
{
	SDL_DestroyRenderer(m_renderer);
}

SDL_Renderer* RendererEngine::getRenderer()
{
	return m_renderer;
}

