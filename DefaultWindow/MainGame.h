#pragma once

#include "Define.h"
#include "Player.h"
#include "Bullet.h"
#include "Monster.h"
#include "AbstractFactory.h"
#include <algorithm>

class CMainGame
{
public:
	CMainGame();
	~CMainGame();

public:
	void		Initialize();
	void		Update();
	void		Late_Update();
	void		Render();
	void		Release();

private:
	HDC			m_DC;
	CObj*		m_pPlayer;
	list<CObj*> m_ObjList[OBJ_END];
};

