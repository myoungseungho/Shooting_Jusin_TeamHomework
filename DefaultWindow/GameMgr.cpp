#include "stdafx.h"
#include "GameMgr.h"
#include "SceneMgr.h"
#include "Define.h"
#include "ObjMgr.h"

CGameMgr* CGameMgr::m_pInstance = nullptr;
CGameMgr::CGameMgr() : m_iCurrentScore(0.f), m_MaxStage(SCENE_3), m_currentStage(SCENE_1), bGameEnd(false)
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
	m_iCurrentScore = 0.f;
}

int CGameMgr::GetCurrentScore()
{
	return m_iCurrentScore;
}

void CGameMgr::SetCurrentScore(int _iAddScore)
{
	m_iCurrentScore += _iAddScore;
}

void CGameMgr::InitCurrentStage()
{
	m_currentStage = SCENE_1;
}

int CGameMgr::GetCurrentStage()
{
	return m_currentStage;
}

void CGameMgr::StageUp()
{
	m_currentStage = static_cast<SCENEID>(static_cast<int>(m_currentStage) + 1);

	//스테이지 업
	if (m_currentStage != SCENE_END)
	{
		//아이템, 적 제거, 불렛 제거
		CObjMgr::Get_Instance()->RemoveAllObjectsExceptPlayer();

		//화면 갱신
		HDC m_DC = GetDC(g_hWnd);
		Rectangle(m_DC, 0, 0, WINCX, WINCY);
	}
	else
		OnGameEnd();
}


void CGameMgr::OnGameEnd()
{
	//아이템, 적 제거, 불렛 제거
	CObjMgr::Get_Instance()->RemoveAllObjectsExceptPlayer();
	//게임 종료 디스플레이
	CDisplayMgr::Get_Instance()->DisplayGameOver();
	//현재 점수 초기화
	InitCurrentScore();
	//현재 스테이지 초기화
	InitCurrentStage();

	bGameEnd = true;
}
