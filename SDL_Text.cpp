#include "SDL_Text.h"

bool SDL_Text::init()
{
	// Initialize SDL_ttf
	if (TTF_Init() == -1) {
		printf("SDL_ttf could not initialize! TTF_Error: %s\n", TTF_GetError());
		return false;
	}
	else
	{
		// specify the path to your font file and font size
		m_Font = TTF_OpenFont(M_MY_FONT, 32); 

		if (!m_Font) {
			printf("Failed to load font: %s\n", TTF_GetError());
			return false;
		}
	}
	return true;
}

bool SDL_Text::createTexturefromText(RendererEngine* renderer, std::string score)
{
	bool createSurfaceOfText = createSurfaceFromText(score);

	if (createSurfaceOfText)
	{
		m_textureOfText = SDL_CreateTextureFromSurface(renderer->getRenderer(), m_surfaceOfText);

		if (!m_textureOfText)
		{
			printf("Failed to create text texture: %s\n", SDL_GetError());
			return false;
		}
		return true;
	}
	return false;
}

void SDL_Text::renderText(RendererEngine* renderer, int screenWidth, int screenHeight)
{
	int x = screenWidth - m_surfaceOfText->w;
	int y = 0; // screenHeight - m_surfaceOfText->h;
	renderer->drawQuad(x, y, m_surfaceOfText->w, m_surfaceOfText->h, m_textureOfText);
	
	// Get rid of old surface
	SDL_FreeSurface(m_surfaceOfText);
}

void SDL_Text::close()
{
	// Free up texture
	SDL_DestroyTexture(m_textureOfText);
	m_textureOfText = NULL;
	// Free font
	TTF_CloseFont(m_Font);
	m_Font = NULL;
	TTF_Quit();
}

bool SDL_Text::createSurfaceFromText(std::string score)
{
	// Create surface with rendered text
	// Black color for text
	SDL_Color textColor = { 0x00, 0x00, 0x00, 0xFF }; 

	std::string temp = "Score: " + score;
	const char* textToRender = temp.c_str();
	m_surfaceOfText = TTF_RenderText_Solid(m_Font, textToRender, textColor);

	if (!m_surfaceOfText) {
		printf("Failed to create text surface: %s\n", TTF_GetError());
		return false;
	}
	
	return true;
}
