#include "stdafx.h"
#include "Item.h"
#include "CollisionMgr.h"
void CItem::Initialize()
{
	m_fSpeed = 3.f;

	//���� ������ ��ġ 
}

int CItem::Update()
{
	if (OBJ_DEAD)
		m_bDead = true;
	srand();
	rand();
	m_tInfo.fY += m_fSpeed;
	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CItem::Late_Update()
{
	//�浹����
	// 1. �ڽ� �簢��
	if (m_tRect.left <= 0 || m_tRect.right >= WINCX
		|| m_tRect.top <= 0 || m_tRect.bottom >= WINCY)
	{

	}

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
