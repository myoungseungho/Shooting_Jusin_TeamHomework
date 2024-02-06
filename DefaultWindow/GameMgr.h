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
	void InitCurrentScore() { m_iCurrentScore = 0.f; };
	int GetCurrentScore() { return m_iCurrentScore; };
	void SetCurrentScore(int _iAddScore) { m_iCurrentScore += _iAddScore; };

	void InitCurrentStage() { m_currentStage = SCENE_1; };
	int GetCurrentStage() { return m_currentStage; }
	void SetCurrentStage(SCENEID _iStage)
	{
		if (_iStage > m_MaxStage)
			return;

		m_currentStage = _iStage;
	}

	bool Check_GameOver();
	bool OnGameEnd();
	bool bPlayerDie;

private:
	int m_iCurrentScore;
	static CGameMgr* m_pInstance;

	SCENEID m_currentStage;
	const SCENEID m_MaxStage;

};


