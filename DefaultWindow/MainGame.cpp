#include "stdafx.h"
#include "MainGame.h"
#include "SceneMgr.h"
#include "ObjMgr.h"
#include "GameMgr.h"
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

	CSceneMgr::Get_Instance()->DisPlayTitle();

	//플레이어 생성
	CObjMgr::Get_Instance()->Add_Object(OBJ_PLAYER, CAbstractFactory<CPlayer>::Create());
	//몬스터 생성
	CObjMgr::Get_Instance()->Add_Object(OBJ_MONSTER, CAbstractFactory<CMonster>::Create());
}

void CMainGame::Update()
{
	CObjMgr::Get_Instance()->Update();
	if (GetAsyncKeyState('C') & 0x8000)
	{
		CGameMgr::Get_Instance()->bPlayerDie = true;
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
}

void CMainGame::Release()
{
	CObjMgr::Get_Instance()->Release();

	ReleaseDC(g_hWnd, m_DC);
}
