#pragma once
#include "Item.h"

class Item;
class CItemSpawnMgr
{
public:
	CItemSpawnMgr();
	~CItemSpawnMgr();
public:
	void SetItem(Item*);
private:
	Item* m_pAttackItem;
	Item* m_pLifeItem;
};

