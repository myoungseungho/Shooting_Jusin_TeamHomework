#include "stdafx.h"
#include "ObjMgr.h"
#include "CollisionMgr.h"
#include "algorithm"
#include "GameMgr.h"

CObjMgr* CObjMgr::m_pInstance = nullptr;

CObjMgr::CObjMgr()
{
}

CObjMgr::~CObjMgr()
{
	Release();
}

void CObjMgr::Add_Object(OBJID eID, CObj* pObj)
{
	if (eID >= OBJ_END || pObj == nullptr)
		return;

	m_ObjList[eID].push_back(pObj);
}



void CObjMgr::RemoveAllObjectsExceptPlayer()
{
	//플레이어는 삭제하면 안됨
	for (size_t i = OBJ_BULLET; i < OBJ_END; ++i)
	{
		for_each(m_ObjList[i].begin(), m_ObjList[i].end(), Safe_Delete<CObj*>);
		m_ObjList[i].clear();
	}
}

int CObjMgr::Update()
{
	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for (auto iter = m_ObjList[i].begin();
			iter != m_ObjList[i].end(); )
		{
			int iResult = (*iter)->Update();

			if (OBJ_DEAD == iResult)
			{
				Safe_Delete<CObj*>(*iter);
				iter = m_ObjList[i].erase(iter);
			}
			else
				++iter;
		}
	}


	return 0;
}

void CObjMgr::Late_Update()
{

	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for (auto& iter : m_ObjList[i])
		{
			iter->Late_Update();
		}
	}

	CCollisionMgr::Collision_Rect(m_ObjList[OBJ_PLAYER], m_ObjList[OBJ_ITEM]);
}

void CObjMgr::Render(HDC hDC)
{

	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for (auto& iter : m_ObjList[i])
		{
			iter->Render(hDC);
		}
	}
}

void CObjMgr::Release()
{
	//플레이어는 삭제하면 안됨
	for (size_t i = 0; i < OBJ_END; ++i)
	{
		for_each(m_ObjList[i].begin(), m_ObjList[i].end(), Safe_Delete<CObj*>);
		m_ObjList[i].clear();
	}
}
