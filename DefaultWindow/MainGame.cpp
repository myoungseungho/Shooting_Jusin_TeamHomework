#include "stdafx.h"
#include "MainGame.h"
#include "SceneMgr.h"


CMainGame::CMainGame()
	:m_DC(NULL), m_pPlayer(nullptr)
{
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	m_DC = GetDC(g_hWnd);

	//�÷��̾� ����
	m_ObjList[OBJ_PLAYER].push_back(CAbstractFactory<CPlayer>::Create());

	//���� ����
	CObj* monster = CAbstractFactory<CMonster>::Create();

}

void CMainGame::Update()
{
	//�Ϲ� Update���� ������, �浹�˻� ���Ŀ� �ش� OBj�� OBJ_DEAD��� �����̳ʿ��� ����
	for (unsigned int i = 0; i < OBJ_END; i++)
	{
		for (auto iter = m_ObjList[i].begin(); iter != m_ObjList[i].end();)
		{
			int iResult = (*iter)->Update();
			if (iResult == OBJ_DEAD)
			{
				Safe_Delete((*iter));
				iter = m_ObjList[i].erase(iter);
			}
			else
				++iter;
		}
	}
}

void CMainGame::Late_Update()
{
	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for (auto& iter : m_ObjList[i])
		{
			iter->Late_Update();
		}
	}
}

void CMainGame::Render()
{
	Rectangle(m_DC, 0, 0, WINCX, WINCY);

	for (unsigned int i = 0; i < OBJ_END; i++)
	{
		for (auto iter : m_ObjList[i])
		{
			iter->Render(m_DC);
		}
	}

	CSceneMgr::DisplayScoreAndStage();
}

void CMainGame::Release()
{
	for (unsigned int i = 0; i < OBJ_END; i++)
	{
		for_each(m_ObjList[i].begin(), m_ObjList[i].end(), Safe_Delete<CObj*>);
	}

	ReleaseDC(g_hWnd, m_DC);
}
