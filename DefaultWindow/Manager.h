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

	//���������
	CManager(const CManager&) = delete;
	//���Կ�����
	CManager& operator=(const CManager&) = delete;

	template<typename T>
	static T* GetInstance() {};


private:
	static CSingleton* m_pSingleton;
	static CSceneMgr* m_pSceneMgr;
	static CCollisionMgr* m_pCollisionMgr;
};
