#include "stdafx.h"
#include "DisPlayMgr.h"
#include "GameMgr.h"
#include "Define.h"

CDisplayMgr* CDisplayMgr::m_pInstance = nullptr;

CDisplayMgr::CDisplayMgr()
{
}

CDisplayMgr::~CDisplayMgr()
{
	Release();
}

void CDisplayMgr::Release()
{
}

void CDisplayMgr::DisPlayTitle()
{
	HDC m_DC = GetDC(g_hWnd);

	TCHAR	szBuffTitle[32] = L"";
	TCHAR	szBuffPeople[32] = L"";
	TCHAR	szBuffReadyTime[32] = L"";

	DWORD tick = GetTickCount64();
	int iSecond = 5;
	float fInterval = 1000;

	while (true)
	{
		if (fInterval >= 1000)
		{
			int iOffsetSecond = iSecond -1;
			swprintf_s(szBuffTitle, L"팀과제 1 : 슈팅 게임");	// 모든 서식 문자를 지원
			swprintf_s(szBuffPeople, L" 변수기 강태욱 명승호");	// 모든 서식 문자를 지원
			swprintf_s(szBuffReadyTime, L"%d", iOffsetSecond);	// 모든 서식 문자를 지원
			TextOut(m_DC,		// 문자열을 복사할 화면 dc
				WINCX * 0.5 - 70.f,			// 출력할 윈도우의 x,y 위치를 전달
				WINCY * 0.5f - 200.f,
				szBuffTitle,		// 출력할 문자열의 시작 주소
				lstrlen(szBuffTitle)); // 문자열의 순수 길이

			TextOut(m_DC,		// 문자열을 복사할 화면 dc
				WINCX * 0.5 - 80.f,			// 출력할 윈도우의 x,y 위치를 전달
				WINCY * 0.5f - 100.f,
				szBuffPeople,		// 출력할 문자열의 시작 주소
				lstrlen(szBuffPeople)); // 문자열의 순수 길이

			TextOut(m_DC,		// 문자열을 복사할 화면 dc
				WINCX * 0.5,			// 출력할 윈도우의 x,y 위치를 전달
				WINCY * 0.5f,
				szBuffReadyTime,		// 출력할 문자열의 시작 주소
				lstrlen(szBuffReadyTime)); // 문자열의 순수 길이

			fInterval = 0.f;
			--iSecond;
			tick = GetTickCount64();
			continue;
		}

		fInterval = GetTickCount64() - tick;

		if (iSecond == 0)
			break;
	}
}

void CDisplayMgr::DisplayScoreAndStage()
{
	HDC m_DC = GetDC(g_hWnd);
	int iCurrentScore = CGameMgr::Get_Instance()->GetCurrentScore();

	TCHAR	szBuffEnd[32] = L"";
	TCHAR	szBuffScore[32] = L"";
	TCHAR	szBuffStage[32] = L"";

	int currentStage = CGameMgr::Get_Instance()->GetCurrentStage();
	swprintf_s(szBuffEnd, L"종료");	// 모든 서식 문자를 지원
	swprintf_s(szBuffScore, L"현재 점수 : %d", iCurrentScore);	// 모든 서식 문자를 지원
	swprintf_s(szBuffStage, L"현재 스테이지 : %d", currentStage);	// 모든 서식 문자를 지원

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

void CDisplayMgr::DisplayGameOver()
{
	HDC m_DC = GetDC(g_hWnd);
	Rectangle(m_DC, 0, 0, WINCX, WINCY);
	DisplayScoreAndStage();

	DWORD tick = GetTickCount64();
	float second = 5;
	while (true)
	{
		float fInterval = GetTickCount64() - tick;
		if (fInterval >= 1000 * second)
		{
			break;
		}
	}
	Rectangle(m_DC, 0, 0, WINCX, WINCY);
}

