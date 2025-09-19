#include "ClickTarget.h"

enum keydowntype
{
	MOUSEDOWN = 1,
};

bool ClickTarget::init()
{
	m_window = new Window();
	m_renderer = new RendererEngine();
	m_target = new TargetShape();
	m_text = new SDL_Text();
	if (m_window->init())
	{
		if (!m_text->init())
			return false;
		m_renderer->init(m_window->getRenderer());
		m_target->init(m_window->getScreenHeight(), m_window->getScreenWidth());
		return true;
	}
	return false;
}

void ClickTarget::gameLoop()
{
	//Main loop flag
	bool quit = false;

	while (!quit)
	{
		// check for input events
		while (m_window->checkPollEvents())
		{
			//User requests quit
			if (m_window->isPollEventQuit())
			{
				quit = true;
			}
			else
			{
				if (m_window->getKeyDownType() == MOUSEDOWN)
				{
					int x, y;
					SDL_GetMouseState(&x, &y);
					m_target->setMouseInput(x, y);
				}
			}
		}
		int targetState = m_target->getTargetState();
		switch (targetState)
		{
		case START:
			m_target->generateTarget();
			//m_target->drawTarget(m_renderer);
			break;
		case CLICKABLE:
			m_target->updateTarget();
			break;
		case END:
			m_target->endTarget();
			m_clearWindow = true;
			break;
		}
		
		drawWindow();
	}
}

void ClickTarget::close()
{
	m_window->close();
	m_renderer->close();
}

ClickTarget::~ClickTarget()
{
	delete m_window;
	delete m_renderer;
	delete m_target;
	delete m_text;
	m_window = nullptr;
	m_renderer = nullptr;
	m_target = nullptr;
	m_text = nullptr;
}

void ClickTarget::drawWindow()
{
	m_renderer->clearScreen();
	m_target->drawTarget(m_renderer);

	if (!m_clearWindow)
	{
		m_target->drawTarget(m_renderer);
	}
	else
	{
		m_clearWindow = false;
	}

	displayScore();

	SDL_RenderPresent(m_renderer->getRenderer());
}

void ClickTarget::displayScore()
{
	std::string score = std::to_string(m_target->getScore());
	m_text->createTexturefromText(m_renderer, score);
	m_text->renderText(m_renderer, m_window->getScreenWidth(), m_window->getScreenHeight());
}
