#include "stdafx.h"
#include "GameMgr.h"
#include "SceneMgr.h"
#include "Define.h"
#include "ObjMgr.h"

CGameMgr* CGameMgr::m_pInstance = nullptr;
CGameMgr::CGameMgr() : m_iCurrentScore(0.f), m_MaxStage(SCENE_3), m_currentStage(SCENE_1), bPlayerDie(false)
{
}

CGameMgr::~CGameMgr()
{
	Release();
}

void CGameMgr::Release()
{
}


bool CGameMgr::OnGameEnd()
{
	if (!Check_GameOver())
		return false;

	//아이템, 적 제거, 불렛 제거
	CObjMgr::Get_Instance()->RemoveAllObjectsExceptPlayer();
	//게임 종료 디스플레이
	CSceneMgr::Get_Instance()->DisplayGameOver();
	//현재 점수 초기화
	InitCurrentScore();
	//현재 스테이지 초기화
	InitCurrentStage();

	return true;
}

bool CGameMgr::Check_GameOver()
{
	if (m_currentStage == SCENE_END || bPlayerDie == true)
		return true;
	else
		return false;
}
