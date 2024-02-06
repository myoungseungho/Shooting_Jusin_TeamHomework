#pragma once

#include "Define.h"
#include "Player.h"
#include "Bullet.h"
#include "Monster.h"
#include "AbstractFactory.h"
#include "CollisionMgr.h"
#include <algorithm>
#include "Scene_1.h"
#include "Scene_2.h"
#include "Scene_3.h"

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
	void		Info_Render();
private:
	HDC			m_DC;
	CScene* 	m_Scene_1;
	CScene* 	m_Scene_2;
	CScene* 	m_Scene_3;
};

