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
	m_currTime -= deltaTime;
}

void FunctionTimer::reset() {
	m_currTime = m_time;
}
