#include "stdafx.h"
#include "Monster.h"

CMonster::CMonster()
{
}

CMonster::~CMonster()
{
	Release();
}

void CMonster::Initialize()
{
}

int CMonster::Update()
{
	if (m_bDead)
		return OBJ_DEAD;


	return OBJ_NOEVENT;
}

void CMonster::Late_Update()
{
}

void CMonster::Render(HDC hDC)
{
}

void CMonster::Release()
{
}
