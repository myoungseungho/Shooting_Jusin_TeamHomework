#pragma once
#include "Manager.h"
class CSceneMgr : public CManager
{
private:
	CSceneMgr();
	friend class CManager;
	virtual ~CSceneMgr();
};

