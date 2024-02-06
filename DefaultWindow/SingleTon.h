#pragma once
#include "Manager.h"
class CSingleton : public CManager
{
private:
	CSingleton();
	friend class CManager;
	virtual ~CSingleton();
public:
};

