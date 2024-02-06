#pragma once
class CSingleton
{
private:
	CSingleton();
	virtual ~CSingleton();
public:
	static int GetCurrentScore();
	static void SetCurrentScore(int _iAddScore);
private:
	static int m_iCurrentScore;
};


