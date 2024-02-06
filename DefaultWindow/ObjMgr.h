#pragma once
#include "Obj.h"

class CObjMgr
{
private:
	CObjMgr();
	~CObjMgr();

public:
	int		Update();
	void	Late_Update();
	void	Render(HDC hDC);
	void	Release();
public:
	void    Add_Object(OBJID eID, CObj* pObj);
	void	RemoveAllObjectsExceptPlayer();
public:
	static CObjMgr* Get_Instance()
	{
		if (m_pInstance == nullptr)
			m_pInstance = new CObjMgr;

		return m_pInstance;
	}

	static void Destory_Instance()
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

private:
	static CObjMgr* m_pInstance;
	list<CObj*>		m_ObjList[OBJ_END];
};

