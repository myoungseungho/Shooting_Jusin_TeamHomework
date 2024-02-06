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
	void DisPlayTitle();
	void DisplayScoreAndStage();
	void DisplayGameOver();

private:
	static CSceneMgr* m_pInstance;
};

