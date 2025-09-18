#include "TargetShape.h"

void TargetShape::init(int screenHeight, int screenWidth)
{
	m_xBound = screenWidth;
	m_yBound = screenHeight;
	m_targetSize = screenWidth / 10;
	m_state = START;
	srand(time(0));
}

void TargetShape::generateCoordinates()
{
	m_X = rand() % (m_xBound + 1 - m_targetSize);
	m_Y = rand() % (m_yBound + 1 - m_targetSize);
}

void TargetShape::generateTarget()
{
	generateCoordinates();

	// set up the timer;	
	m_timer.setAvailableTimeToClick();
	m_timer.startTime();
	m_state = CLICKABLE;
}

void TargetShape::drawTarget(RendererEngine* renderer) const
{
	// white
	// black
	// blue
	// red
	// yellow
	int numColors = 5;
	int alpha = 0xFF;
	// we have to shrink from both sides to keep the squares center
	int coorOffsetBase = m_targetSize / (numColors * 2);
	int coorOffset = 0;
	int curSquareSize = m_targetSize;

	for (int i = 0; i < 5; i++)
	{
		if (i != 0)
		{
			coorOffset = coorOffsetBase * i;
			curSquareSize = m_targetSize - (coorOffset * 2);
		}
		switch (i)
		{
		case 0:
			// WHITE = 0xFFFFFF
			renderer->drawBlock(m_X, m_Y, m_targetSize, m_targetSize, 0xFF, 0xFF, 0xFF, alpha);
			renderer->drawSquare(m_X, m_Y, m_targetSize, m_targetSize, 0x00, 0x00, 0x00);
			break;
		case 1:
			// BLACK - 0x000000
			renderer->drawBlock(m_X + coorOffset, m_Y + coorOffset, curSquareSize, curSquareSize, 0x00, 0x00, 0x00, alpha);
			break;
		case 2:
			// LIGHT BLUE = 0x00B4E4
			renderer->drawBlock(m_X + coorOffset, m_Y + coorOffset, curSquareSize, curSquareSize, 0x00, 0xB4, 0xE4, alpha);
			break;
		case 3:
			// RED = 0xFF0000
			renderer->drawBlock(m_X + coorOffset, m_Y + coorOffset, curSquareSize, curSquareSize, 0xFF, 0x00, 0x00, alpha);
			break;
		case 4:
			// YELLOW = 0xFFFF00
			renderer->drawBlock(m_X + coorOffset, m_Y + coorOffset, curSquareSize, curSquareSize, 0xFF, 0xFF, 0x00, alpha);
		}
	}
}

void TargetShape::updateTarget()
{
	int endTargetX = m_X + m_targetSize;
	int endTargetY = m_Y + m_targetSize;

	if (m_mouseX >= m_X && m_mouseX <= endTargetX && m_mouseY >= m_Y && m_mouseY <= endTargetY)
	{
		m_score++;
		m_state = END;
	}

	if (m_timer.checkTime())
	{
		m_state = END;
	}
}

void TargetShape::endTarget(/*RendererEngine* renderer*/)
{
	//renderer->clearScreen();
	m_mouseX = -1;
	m_mouseY = -1;
	m_state = START;
}

void TargetShape::setMouseInput(int x, int y)
{
	m_mouseX = x;
	m_mouseY = y;
}

int TargetShape::getTargetState() const
{
	return m_state;
}

int TargetShape::getScore() const
{
	return m_score;
}
