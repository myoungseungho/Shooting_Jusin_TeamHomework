#include "stdafx.h"
#include "GameMgr.h"

CGameMgr* CGameMgr::m_pInstance = nullptr;
CGameMgr::CGameMgr() : m_iCurrentScore(0)
{
}

CGameMgr::~CGameMgr()
{
	Release();
}

void CGameMgr::Release()
{
}

void CGameMgr::InitCurrentScore()
{
	m_iCurrentScore = 1;
}

int CGameMgr::GetCurrentScore()
{
	return m_iCurrentScore;
}

void CGameMgr::SetCurrentScore(int _iAddScore)
{
	m_iCurrentScore += _iAddScore;
}