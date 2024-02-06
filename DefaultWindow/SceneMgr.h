#pragma once
class CSceneMgr
{
private:
	CSceneMgr();
	virtual ~CSceneMgr();
public:
	void	Release();
public:
	static		CSceneMgr* Get_Instance()
	{
		if (!m_pInstance)
			m_pInstance = new CSceneMgr;

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
	void InitCurrentStage();
	int GetCurrentStage() { return m_currentStage; }
	void SetCurrentStage(int _iStage)
	{
		if (_iStage > m_MaxStage)
			return;

		m_currentStage = _iStage;
	}
	void DisPlayTitle();
	void DisplayScoreAndStage();
	void Retry();
public:
	const int m_MaxStage;
private:
	static CSceneMgr* m_pInstance;
	int m_currentStage;
};

