#include "stdafx.h"
#include "SingleTon.h"

int CSingleton::m_iCurrentScore = 0;

CSingleton::CSingleton()
{
}

CSingleton::~CSingleton()
{
}

int CSingleton::GetCurrentScore()
{
	return m_iCurrentScore;
}

void CSingleton::SetCurrentScore(int _iAddScore)
{
	m_iCurrentScore += _iAddScore;
}