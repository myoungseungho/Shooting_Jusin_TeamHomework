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

	//타이틀 화면 호출
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
	//모든 오브젝트 Update
	CObjMgr::Get_Instance()->Update();

	// 현재 스테이지 상태를 가져옵니다.
	int iCurrentStage = CGameMgr::Get_Instance()->GetCurrentStage();

	switch (iCurrentStage)
	{
	case SCENE_1:
		// 첫 번째 스테이지에서 수행할 작업들
		// 예: 플레이어 생성, 적 생성 등
		dynamic_cast<CScene_1*>(m_Scene_1)->Update();

		// 1씬 보스 제거
		if (CGameMgr::Get_Instance()->bBossKilled)
		{
			CGameMgr::Get_Instance()->bBossKilled = false;
			// 다음 스테이지로 넘어가기 위한 준비 작업
			CGameMgr::Get_Instance()->StageUp();
		}
		break;
	case SCENE_2:
		dynamic_cast<CScene_2*>(m_Scene_2)->Update();
		// 2씬 보스 제거
		//if (/*IsStage2Clear()*/)
		//{
		//	// 다음 스테이지로 넘어가기 위한 준비 작업
		//	CGameMgr::Get_Instance()->StageUp();
		//}
		break;
	case SCENE_3:
		// 세 번째 스테이지에서 수행할 작업들
		dynamic_cast<CScene_3*>(m_Scene_3)->Update();

		// 3씬 보스 제거
		//if (/*IsStage3Clear()*/)
		//{
		//	// 다음 스테이지로 넘어가기 위한 준비 작업
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

	swprintf_s(szBuffScore, L"현재 점수 : %d", iCurrentScore);	// 모든 서식 문자를 지원
	swprintf_s(szBuffStage, L"현재 스테이지 : %d", iCurrentStage);	// 모든 서식 문자를 지원

	TextOut(m_DC,		// 문자열을 복사할 화면 dc
		50,			// 출력할 윈도우의 x,y 위치를 전달
		530,
		szBuffScore,		// 출력할 문자열의 시작 주소
		lstrlen(szBuffScore)); // 문자열의 순수 길이

	TextOut(m_DC,		// 문자열을 복사할 화면 dc
		50,			// 출력할 윈도우의 x,y 위치를 전달
		550,
		szBuffStage,		// 출력할 문자열의 시작 주소
		lstrlen(szBuffStage)); // 문자열의 순수 길이

}
