#pragma once
class FunctionTimer
{
public:
	FunctionTimer(float a_time);
	~FunctionTimer();

	void update(float deltaTime);
	void reset();
	float m_time;
	float m_currTime;
};

