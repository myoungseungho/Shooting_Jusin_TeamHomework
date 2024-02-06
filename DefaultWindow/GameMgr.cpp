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

	//������, �� ����, �ҷ� ����
	CObjMgr::Get_Instance()->RemoveAllObjectsExceptPlayer();
	//���� ���� ���÷���
	CSceneMgr::Get_Instance()->DisplayGameOver();
	//���� ���� �ʱ�ȭ
	InitCurrentScore();
	//���� �������� �ʱ�ȭ
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
