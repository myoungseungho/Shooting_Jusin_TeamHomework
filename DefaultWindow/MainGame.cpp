#include "stdafx.h"
#include "MainGame.h"
#include "DisPlayMgr.h"
#include "ObjMgr.h"
#include "GameMgr.h"
#include "Scene.h"
CMainGame::CMainGame()
	:m_DC(NULL)
{
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	m_DC = GetDC(g_hWnd);

	//Ÿ��Ʋ ȭ�� ȣ��
	CDisplayMgr::Get_Instance()->DisPlayTitle();
	
	if (m_Scene_1 == nullptr)
		m_Scene_1 = new CScene_1;
	if (m_Scene_2 == nullptr)
		m_Scene_2 = new CScene_2;
	if (m_Scene_3 == nullptr)
		m_Scene_3 = new CScene_3;
}

void CMainGame::Update()
{ 
	//��� ������Ʈ Update
	CObjMgr::Get_Instance()->Update();

	// ���� �������� ���¸� �����ɴϴ�.
	int iCurrentStage = CGameMgr::Get_Instance()->GetCurrentStage();

	switch (iCurrentStage)
	{
	case SCENE_1:
		// ù ��° ������������ ������ �۾���
		// ��: �÷��̾� ����, �� ���� ��
		dynamic_cast<CScene_1*>(m_Scene_1)->Update();

		// 1�� ���� ����
		if (CGameMgr::Get_Instance()->bBossKilled)
		{
			CGameMgr::Get_Instance()->bBossKilled = false;
			// ���� ���������� �Ѿ�� ���� �غ� �۾�
			CGameMgr::Get_Instance()->StageUp();
		}
		break;
	case SCENE_2:
		dynamic_cast<CScene_2*>(m_Scene_2)->Update();
		// 2�� ���� ����
		//if (/*IsStage2Clear()*/)
		//{
		//	// ���� ���������� �Ѿ�� ���� �غ� �۾�
		//	CGameMgr::Get_Instance()->StageUp();
		//}
		break;
	case SCENE_3:
		// �� ��° ������������ ������ �۾���
		dynamic_cast<CScene_3*>(m_Scene_3)->Update();

		// 3�� ���� ����
		//if (/*IsStage3Clear()*/)
		//{
		//	// ���� ���������� �Ѿ�� ���� �غ� �۾�
		//	CGameMgr::Get_Instance()->StageUp();
		//}
		break;
	}




	
}

void CMainGame::Late_Update()
{
	CObjMgr::Get_Instance()->Late_Update();
}

void CMainGame::Render()
{
	Rectangle(m_DC, 0, 0, WINCX, WINCY);
	CObjMgr::Get_Instance()->Render(m_DC);
	Info_Render();
}

void CMainGame::Release()
{
	CObjMgr::Get_Instance()->Release();
	ReleaseDC(g_hWnd, m_DC);
}

void CMainGame::Info_Render()
{
	int iCurrentScore = CGameMgr::Get_Instance()->GetCurrentScore();
	int iCurrentStage = CGameMgr::Get_Instance()->GetCurrentStage();

	TCHAR	szBuffScore[32] = L"";
	TCHAR	szBuffStage[32] = L"";

	swprintf_s(szBuffScore, L"���� ���� : %d", iCurrentScore);	// ��� ���� ���ڸ� ����
	swprintf_s(szBuffStage, L"���� �������� : %d", iCurrentStage);	// ��� ���� ���ڸ� ����

	TextOut(m_DC,		// ���ڿ��� ������ ȭ�� dc
		50,			// ����� �������� x,y ��ġ�� ����
		530,
		szBuffScore,		// ����� ���ڿ��� ���� �ּ�
		lstrlen(szBuffScore)); // ���ڿ��� ���� ����

	TextOut(m_DC,		// ���ڿ��� ������ ȭ�� dc
		50,			// ����� �������� x,y ��ġ�� ����
		550,
		szBuffStage,		// ����� ���ڿ��� ���� �ּ�
		lstrlen(szBuffStage)); // ���ڿ��� ���� ����

}
