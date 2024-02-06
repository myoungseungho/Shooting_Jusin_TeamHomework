#include "stdafx.h"
#include "SceneMgr.h"
#include "SingleTon.h"
#include "Define.h"

const int CSceneMgr::m_MaxStage = 3;
int CSceneMgr::m_currentStage = 1;


CSceneMgr::CSceneMgr()
{
}

CSceneMgr::~CSceneMgr()
{
}

void CSceneMgr::DisplayScoreAndStage()
{
	int iCurrentScore = CSingleton::GetCurrentScore();
	HDC m_DC = GetDC(g_hWnd);

	TCHAR	szBuffEnd[32] = L"";
	TCHAR	szBuffScore[32] = L"";
	TCHAR	szBuffStage[32] = L"";


	swprintf_s(szBuffEnd, L"종료");	// 모든 서식 문자를 지원
	swprintf_s(szBuffScore, L"현재 점수 : %d", iCurrentScore);	// 모든 서식 문자를 지원
	swprintf_s(szBuffStage, L"현재 스테이지 : %d", m_currentStage);	// 모든 서식 문자를 지원

	TextOut(m_DC,		// 문자열을 복사할 화면 dc
		WINCX * 0.5 - 20.f,			// 출력할 윈도우의 x,y 위치를 전달
		WINCY * 0.5f - 100.f,
		szBuffEnd,		// 출력할 문자열의 시작 주소
		lstrlen(szBuffEnd)); // 문자열의 순수 길이

	TextOut(m_DC,		// 문자열을 복사할 화면 dc
		WINCX * 0.5 - 40.f,			// 출력할 윈도우의 x,y 위치를 전달
		WINCY * 0.5f - 20.f,
		szBuffScore,		// 출력할 문자열의 시작 주소
		lstrlen(szBuffScore)); // 문자열의 순수 길이

	TextOut(m_DC,		// 문자열을 복사할 화면 dc
		WINCX * 0.5 - 40.f,			// 출력할 윈도우의 x,y 위치를 전달
		WINCY * 0.5f,
		szBuffStage,		// 출력할 문자열의 시작 주소
		lstrlen(szBuffStage)); // 문자열의 순수 길이
}
