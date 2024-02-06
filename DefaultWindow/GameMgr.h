#pragma once
#include "Define.h"
class CGameMgr
{
private:
	CGameMgr();
	virtual ~CGameMgr();
public:
	void	Release();
public:
	static		CGameMgr* Get_Instance()
	{
		if (!m_pInstance)
			m_pInstance = new CGameMgr;

		return m_pInstance;
	}

	static void	Destroy_Instance()
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

public:
	void InitCurrentScore();
	int GetCurrentScore();
	void SetCurrentScore(int);


	void InitCurrentStage();
	int GetCurrentStage();

	void StageUp();
	void OnGameEnd();

	bool bBossKilled;
	bool bGameEnd;

private:
	int m_iCurrentScore;
	static CGameMgr* m_pInstance;

	SCENEID m_currentStage;
	const SCENEID m_MaxStage;

};


