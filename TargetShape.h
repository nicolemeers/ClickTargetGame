#include "Timer.h"
#include "RendererEngine.h"
#pragma once
class TargetShape
{
public:
	void init(int screenHeight, int screenWidth);

	// starting
	void generateCoordinates();
	//void generateColor();
	void generateTarget();
	void drawTarget(RendererEngine* renderer) const;

	void updateTarget();

	void endTarget();
	
	// needed inputs
	void setMouseInput(int x, int y);
	int getTargetState() const;
	int getScore() const;


private:
	int m_X;
	int m_Y;
	int m_xBound;
	int m_yBound;

	int m_targetSize;

	int m_R;
	int m_G;
	int m_B;

	Timer m_timer;

	int m_state;

	int m_mouseX;
	int m_mouseY;

	int m_score;
};

enum targetState
{
	START,
	CLICKABLE,
	END
};
