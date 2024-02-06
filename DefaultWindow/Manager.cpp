#include "stdafx.h"
#include "Manager.h"

CManager::CManager()
{
}

CManager::~CManager()
{
}


template<>
CSingleton* CManager::GetInstance<CSingleton>()
{
    if (m_pSingleton == nullptr)
    {
        m_pSingleton = new CSingleton();
    }
    return m_pSingleton;
}

template<>
CSceneMgr* CManager::GetInstance<CSceneMgr>()
{
    if (m_pSceneMgr == nullptr)
    {
        m_pSceneMgr = new CSceneMgr();
    }
    return m_pSceneMgr;
}

template<>
CCollisionMgr* CManager::GetInstance<CCollisionMgr>()
{
    if (m_pCollisionMgr == nullptr)
    {
        m_pCollisionMgr = new CCollisionMgr();
    }
    return m_pCollisionMgr;
}

// ¼Ò¸êÀÚ ±¸Çö
CManager::~CManager()
{
    delete m_pSingleton;
    delete m_pSceneMgr;
    delete m_pCollisionMgr;
}
