#pragma once
#include "SingleTon.h"
#include "SceneMgr.h"
#include "CollisionMgr.h"
class CManager
{
protected:
	CManager();
	virtual ~CManager();
public:

	//복사생성자
	CManager(const CManager&) = delete;
	//대입연산자
	CManager& operator=(const CManager&) = delete;

	template<typename T>
	static T* GetInstance() {};


private:
	static CSingleton* m_pSingleton;
	static CSceneMgr* m_pSceneMgr;
	static CCollisionMgr* m_pCollisionMgr;
};
