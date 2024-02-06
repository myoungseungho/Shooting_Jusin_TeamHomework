#include "stdafx.h"
#include "Item.h"
#include "CollisionMgr.h"
void CItem::Initialize()
{
	m_fSpeed = 3.f;
}

int CItem::Update()
{
	if (OBJ_DEAD)
		m_bDead = true;

	m_tInfo.fY += m_fSpeed;
	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CItem::Late_Update()
{
	//충돌조건
	// 1. 박스 사각형
	if (m_tRect.left <= 0 || m_tRect.right >= WINCX
		|| m_tRect.top <= 0 || m_tRect.bottom >= WINCY)
		m_bDead = true;
}

void CItem::Render(HDC hDC)
{
}

void CItem::Release()
{
}

void CItem::SetPlayer(CPlayer* _pPlayer)
{
	m_pPlayerCopy = _pPlayer;
}
