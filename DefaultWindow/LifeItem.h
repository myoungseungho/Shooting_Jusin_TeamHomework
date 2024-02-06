#pragma once
#include "Item.h"
class CLifeItem : public CItem
{
public:
    CLifeItem();
    virtual ~CLifeItem();

public:
    void SetPlayerLife();
};

