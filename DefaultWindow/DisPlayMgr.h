#pragma once
class CDisplayMgr
{
private:
	CDisplayMgr();
	virtual ~CDisplayMgr();
public:
	void	Release();
public:
	static		CDisplayMgr* Get_Instance()
	{
		if (!m_pInstance)
			m_pInstance = new CDisplayMgr;

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
	static CDisplayMgr* m_pInstance;
};

