#pragma once

#define WINCX		800
#define WINCY		600

#define PURE		= 0


#define			OBJ_NOEVENT	 0
#define			OBJ_DEAD	 1

template<typename T>
void Safe_Delete(T& Temp)
{
	if (Temp)
	{
		delete Temp;
		Temp = nullptr;
	}
}

typedef struct tagInfo
{
	float	fX;
	float	fY;
	float	fCX;
	float	fCY;

}INFO;

enum OBJID
{
	OBJ_PLAYER,
	OBJ_BULLET,
	OBJ_MONSTER,
	OBJ_MOUSE,
	OBJ_ITEM,
	OBJ_END
};
enum SCENEID
{
	SCENE_1 = 1,
	SCENE_2,
	SCENE_3,
	SCENE_END
};

enum GAMESTATE
{
	GAME_START,
	GAME_RUNNING,
	GAME_OVER,
	GAME_EXIT
};

enum ITEMDIR
{
	ITEMDIR_DOWN,
	ITEMDIR_
};

extern HWND g_hWnd;