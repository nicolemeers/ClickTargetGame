#include "Window.h"

Window::Window()
{
	m_screenHeight = 720;
	m_screenWidth = 1040;
}

Window::~Window()
{
}

bool Window::init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		m_Window = SDL_CreateWindow("Click Target Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_screenWidth, m_screenHeight, SDL_WINDOW_SHOWN);
		if (m_Window == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create renderer for window
			m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);
			if (m_Renderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(m_Renderer, 0xFF, 0xFF, 0xFF, 0xFF);
			}
		}
	}

	return success;
}

void Window::close()
{
	//Destroy window	
	//SDL_DestroyRenderer(m_Renderer); This should be done by the renderer
	SDL_DestroyWindow(m_Window);
	m_Window = NULL;
	m_Renderer = NULL;

	//Quit SDL subsystems
	//IMG_Quit();
	SDL_Quit();
}



int Window::getScreenHeight()
{
	return m_screenHeight;
}

int Window::getScreenWidth()
{
	return m_screenWidth;
}

SDL_Window* Window::getWindow()
{
	return m_Window;
}

SDL_Renderer* Window::getRenderer()
{
	return m_Renderer;
}

bool Window::checkPollEvents()
{
	return (SDL_PollEvent(&e) != 0);
}

bool Window::isPollEventQuit() const
{
	return (e.type == SDL_QUIT);
}

bool Window::isKeydownEventTrue() const
{
	return (e.type == SDL_KEYDOWN);
}

int Window::getKeyDownType() const
{
	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		return 1;
	}
	else 
	{
		return -1;
	}
	return 0;
}
