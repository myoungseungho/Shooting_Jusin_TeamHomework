#pragma once
class CSceneMgr
{
private:
	CSceneMgr();
	virtual ~CSceneMgr();
public:
	static int GetCurrentStage() { return m_currentStage; }
	static void SetCurrentStage(int _iStage)
	{
		if (_iStage > m_MaxStage)
			return;

		m_currentStage = _iStage;
	}
	static void DisplayScoreAndStage();
public:
	static const int m_MaxStage;
private:
	static int m_currentStage;
};

