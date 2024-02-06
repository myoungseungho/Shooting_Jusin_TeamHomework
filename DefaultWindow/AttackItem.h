#pragma once
#include "Item.h"
class CLevelUpItem :public CItem
{
public:
	CLevelUpItem();
	virtual ~CLevelUpItem();

public:
    void LevelUpPlayer();
};  

