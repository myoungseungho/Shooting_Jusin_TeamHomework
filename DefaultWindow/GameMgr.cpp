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

	//�������� ��
	if (m_currentStage != SCENE_END)
	{
		//������, �� ����, �ҷ� ����
		CObjMgr::Get_Instance()->RemoveAllObjectsExceptPlayer();

		//ȭ�� ����
		HDC m_DC = GetDC(g_hWnd);
		Rectangle(m_DC, 0, 0, WINCX, WINCY);
	}
	else
		OnGameEnd();
}


void CGameMgr::OnGameEnd()
{
	//������, �� ����, �ҷ� ����
	CObjMgr::Get_Instance()->RemoveAllObjectsExceptPlayer();
	//���� ���� ���÷���
	CDisplayMgr::Get_Instance()->DisplayGameOver();
	//���� ���� �ʱ�ȭ
	InitCurrentScore();
	//���� �������� �ʱ�ȭ
	InitCurrentStage();

	bGameEnd = true;
}
