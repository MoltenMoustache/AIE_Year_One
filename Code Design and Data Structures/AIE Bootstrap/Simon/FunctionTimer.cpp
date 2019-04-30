#include "FunctionTimer.h"



FunctionTimer::FunctionTimer(float a_time)
{
	m_time = a_time;
	m_currTime = m_time;
}


FunctionTimer::~FunctionTimer()
{

}

void FunctionTimer::update(float deltaTime) {
	if(m_currTime > 0)
		m_currTime -= deltaTime;
}

void FunctionTimer::reset() {
	m_currTime = m_time;
}
