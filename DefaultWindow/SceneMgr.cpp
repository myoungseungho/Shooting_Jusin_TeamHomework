#include "stdafx.h"
#include "SceneMgr.h"
#include "GameMgr.h"
#include "Define.h"

CSceneMgr* CSceneMgr::m_pInstance = nullptr;
CSceneMgr::CSceneMgr() : m_currentStage(0), m_MaxStage(3)
{
}

CSceneMgr::~CSceneMgr()
{
	Release();
}

void CSceneMgr::Release()
{
}

void CSceneMgr::InitCurrentStage()
{
	m_currentStage = 0;
}

void CSceneMgr::DisPlayTitle()
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
			swprintf_s(szBuffTitle, L"������ 1 : ���� ����");	// ��� ���� ���ڸ� ����
			swprintf_s(szBuffPeople, L" ������ ���¿� ���ȣ");	// ��� ���� ���ڸ� ����
			swprintf_s(szBuffReadyTime, L"%d", iOffsetSecond);	// ��� ���� ���ڸ� ����
			TextOut(m_DC,		// ���ڿ��� ������ ȭ�� dc
				WINCX * 0.5 - 70.f,			// ����� �������� x,y ��ġ�� ����
				WINCY * 0.5f - 200.f,
				szBuffTitle,		// ����� ���ڿ��� ���� �ּ�
				lstrlen(szBuffTitle)); // ���ڿ��� ���� ����

			TextOut(m_DC,		// ���ڿ��� ������ ȭ�� dc
				WINCX * 0.5 - 80.f,			// ����� �������� x,y ��ġ�� ����
				WINCY * 0.5f - 100.f,
				szBuffPeople,		// ����� ���ڿ��� ���� �ּ�
				lstrlen(szBuffPeople)); // ���ڿ��� ���� ����

			TextOut(m_DC,		// ���ڿ��� ������ ȭ�� dc
				WINCX * 0.5,			// ����� �������� x,y ��ġ�� ����
				WINCY * 0.5f,
				szBuffReadyTime,		// ����� ���ڿ��� ���� �ּ�
				lstrlen(szBuffReadyTime)); // ���ڿ��� ���� ����

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

void CSceneMgr::DisplayScoreAndStage()
{
	int iCurrentScore = CGameMgr::Get_Instance()->GetCurrentScore();
	HDC m_DC = GetDC(g_hWnd);

	TCHAR	szBuffEnd[32] = L"";
	TCHAR	szBuffScore[32] = L"";
	TCHAR	szBuffStage[32] = L"";


	swprintf_s(szBuffEnd, L"����");	// ��� ���� ���ڸ� ����
	swprintf_s(szBuffScore, L"���� ���� : %d", iCurrentScore);	// ��� ���� ���ڸ� ����
	swprintf_s(szBuffStage, L"���� �������� : %d", m_currentStage);	// ��� ���� ���ڸ� ����

	TextOut(m_DC,		// ���ڿ��� ������ ȭ�� dc
		WINCX * 0.5 - 20.f,			// ����� �������� x,y ��ġ�� ����
		WINCY * 0.5f - 100.f,
		szBuffEnd,		// ����� ���ڿ��� ���� �ּ�
		lstrlen(szBuffEnd)); // ���ڿ��� ���� ����

	TextOut(m_DC,		// ���ڿ��� ������ ȭ�� dc
		WINCX * 0.5 - 40.f,			// ����� �������� x,y ��ġ�� ����
		WINCY * 0.5f - 20.f,
		szBuffScore,		// ����� ���ڿ��� ���� �ּ�
		lstrlen(szBuffScore)); // ���ڿ��� ���� ����

	TextOut(m_DC,		// ���ڿ��� ������ ȭ�� dc
		WINCX * 0.5 - 40.f,			// ����� �������� x,y ��ġ�� ����
		WINCY * 0.5f,
		szBuffStage,		// ����� ���ڿ��� ���� �ּ�
		lstrlen(szBuffStage)); // ���ڿ��� ���� ����
}

void CSceneMgr::Retry()
{
	HDC m_DC = GetDC(g_hWnd);
	Rectangle(m_DC, 0, 0, WINCX, WINCY);

	m_currentStage = 0;
	CGameMgr::Get_Instance()->InitCurrentScore();
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
}
