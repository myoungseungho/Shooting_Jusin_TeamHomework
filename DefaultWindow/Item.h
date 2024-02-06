#pragma once
#include "Obj.h"
#include "Player.h"
class CItem :
	public CObj
{
public:
	void Initialize() override;
	int Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;
public:
	void SetPlayer(CPlayer*);
protected:
	CPlayer* m_pPlayerCopy;
};

