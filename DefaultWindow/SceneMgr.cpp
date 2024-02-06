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
