#include "TargetShape.h"
#include "Window.h"
#include "SDL_Text.h"
#pragma once
class ClickTarget
{
public:
	bool init();
	void gameLoop();
	void close();

	~ClickTarget();
private:

	void drawWindow();
	void displayScore();
	bool m_clearWindow;

	Window* m_window = nullptr;
	RendererEngine* m_renderer = nullptr;
	TargetShape* m_target = nullptr;
	SDL_Text* m_text = nullptr;
};


// need to disaply text for score
