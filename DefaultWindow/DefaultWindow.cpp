// DefaultWindow.cpp : ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "DefaultWindow.h"
#include "MainGame.h"
#include "GameMgr.h"

#define MAX_LOADSTRING 100

// ���� ����:
HINSTANCE hInst;                                // ���� �ν��Ͻ��Դϴ�.
WCHAR szTitle[MAX_LOADSTRING];                  // ���� ǥ���� �ؽ�Ʈ�Դϴ�.
WCHAR szWindowClass[MAX_LOADSTRING];            // �⺻ â Ŭ���� �̸��Դϴ�.
HWND	g_hWnd;
GAMESTATE game_State = GAME_START;
bool bGameOver = false;

// �� �ڵ� ��⿡ ��� �ִ� �Լ��� ������ �����Դϴ�.
ATOM                MyRegisterClass(HINSTANCE hInstance);	// ������ â�� ���� ��Ÿ�� ���� �Լ�
BOOL                InitInstance(HINSTANCE, int);			// â�� �����ϰ� ����ϴ� ����� �Լ�
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);	// ������ �޼��� ó�� �Լ�
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

//�ڵ� : �ü���� �ο��ϴ� ���� �ĺ� ��ȣ(16���� ������ ����)
//
//���ҽ�
//
//1. ���μ���		: ���� �����ϰ� �ִ� ���α׷�(��->��������)
//2. ������			: �����ϴ� ���α׷��� �ڵ��� �帧
//3. ����(������)	: ����

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,				// �޸𸮿� �Ҵ�Ǵ� ��ü, �� ��ü
	_In_opt_ HINSTANCE hPrevInstance,		// ���� ����Ǿ��� �ν��Ͻ��� �ڵ��� �Ѿ��, ���� ��� �ڵ� NULL�� ä����
	_In_ LPWSTR    lpCmdLine,				// �����ڵ� ��� ���� Ÿ��
	_In_ int       nCmdShow)				// �ܼ� â�� �ƴ� ������ â ������ �ǹ�(������ â�� ��Ÿ�� �ɼ� ����)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: ���⿡ �ڵ带 �Է��մϴ�.

	// ���� ���ڿ��� �ʱ�ȭ�մϴ�.
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_DEFAULTWINDOW, szWindowClass, MAX_LOADSTRING);

	MyRegisterClass(hInstance);

	// ���� ���α׷� �ʱ�ȭ�� �����մϴ�.
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_DEFAULTWINDOW));

	MSG msg;
	msg.message = WM_NULL;

	DWORD	dwTime = GetTickCount64();	// 500
	CMainGame		MainGame;


	while (true)
	{
		// PM_REMOVE   : �޼����� �о�Ȱ� ���ÿ� �޼��� ť���� �޼����� ����
		// PM_NOREMOVE : �޼��� ť�� �޼����� �����ϴ����� �ľ�, �޼����� �о������ GetMessage�Լ��� �ٽ� ȣ���ؾ� ��

		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			if (WM_QUIT == msg.message)
				break;

			if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			switch (game_State)
			{
			case GAME_START:
				MainGame.Initialize();
				game_State = GAME_RUNNING;
				break;
			case GAME_RUNNING:
				bGameOver = CGameMgr::Get_Instance()->Check_GameOver();
				if (!bGameOver)
				{
					if (dwTime + 10 < GetTickCount64())
					{
						MainGame.Update();
						MainGame.Late_Update();
						MainGame.Render();
						dwTime = GetTickCount64();
					}
				}
				else
				{
					CGameMgr::Get_Instance()->OnGameEnd();
					game_State = GAME_OVER;
				}
				break;
			case GAME_OVER:
				CGameMgr::Get_Instance()->bPlayerDie = false;
				game_State = GAME_START;
				break;
			case GAME_EXIT:
				break;
			default:
				break;
			}
		}

	}

	return (int)msg.wParam;
}



//
//  �Լ�: MyRegisterClass()
//
//  ����: â Ŭ������ ����մϴ�.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);	// â ������ 

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	// ���θ� �ٽ� �׸��� | ���θ� �ٽ� �׸���
	// ������ â�� ����, ������ ���̰� ��ȭ�� ��� ������ â�� �ٽ� �׸��ٴ� �ɼ�

	wcex.lpfnWndProc = WndProc;	// �����ص� �Լ��� ȣ��Ǿ� �޼����� ó��


	wcex.cbClsExtra = 0;	//�����찡 Ư���� �������� ����ϴ� ������ ����
	wcex.cbWndExtra = 0;

	wcex.hInstance = hInstance;	// ���α׷��� ���� �ĺ� ��ȣ

	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_DEFAULTWINDOW));
	// ������ â�� ����� ������ ����

	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	// â�� ��µ� Ŀ�� ��� ����

	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	// ����

	wcex.lpszMenuName = NULL;//MAKEINTRESOURCEW(IDC_DEFAULTWINDOW);
	// â ��ܿ� �ִ� �޴��� ����
	wcex.lpszClassName = szWindowClass;
	// �������� �̸� ����, ������ ������Ʈ �̸��� ��ġ���� �ۼ�
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
	// â ��ܿ� �ִ� ���� ������ ���

	return RegisterClassExW(&wcex);
}

//
//   �Լ�: InitInstance(HINSTANCE, int)
//
//   ����: �ν��Ͻ� �ڵ��� �����ϰ� �� â�� ����ϴ�.
//
//   ����:
//
//        �� �Լ��� ���� �ν��Ͻ� �ڵ��� ���� ������ �����ϰ�
//        �� ���α׷� â�� ���� ���� ǥ���մϴ�.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // �ν��Ͻ� �ڵ��� ���� ������ �����մϴ�.

	// CreateWindowW : ����� ���� �������� ���� ������(â)�� ����� �Լ�
	// szWindowClass : �ռ� ������ ������ Ŭ������ ������ Ŭ���� �̸��� �״�� �־���
	// szTitle : ������ ��ܿ� �̸��� ��Ÿ�� ���ڿ�
	// WS_OVERLAPPEDWINDOW : ������� �ϴ� �� ��Ÿ��(�⺻ ������ ����ϴ� ���� â ����)
	// CW_USEDEFAULT, 0 : â�� ������ X, Y ��ǥ
	// CW_USEDEFAULT, 0 : â�� ����, ���� ������
	// nullptr : �θ� �����찡 �ִٸ� �θ� ������ �ڵ��� ����, ������ NULL
	// nullptr : �����쿡�� ����� �޴��� �ڵ��� ����, �������Ϳ� ����� �޴� ���¸� ����Ϸ��� NULL
	// hInstance : �����츦 ����� ��ü, ���α׷��� �ڵ��� ����
	// nullptr : �ü���� Ư���� �������� ����ϹǷ� ����� �� ����

	RECT	rc{ 0, 0, WINCX, WINCY };

	// �������� RC = rc ũ�� + �⺻ ������ â ��Ÿ�� + �޴� �� ������ ũ�� ��� ����
	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);

	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0,
		rc.right - rc.left,
		rc.bottom - rc.top,
		nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}

	g_hWnd = hWnd;

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

//
//  �Լ�: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ����:  �� â�� �޽����� ó���մϴ�.
//
//  WM_COMMAND  - ���� ���α׷� �޴��� ó���մϴ�.
//  WM_PAINT    - �� â�� �׸��ϴ�.
//  WM_DESTROY  - ���� �޽����� �Խ��ϰ� ��ȯ�մϴ�.
//

// window�� �⺻ ���̺귯��

//1. kernel : �޸𸮸� �����ϰ� ���α׷��� ����
//2. user : ���� �������̽��� ������ â ����
//3. gdi : ȭ�� ó���� �׷����� ���

//RECT		rc{ 100, 100, 200, 200 };
//list<RECT>	BulletList;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// �޴� ������ ���� �м��մϴ�.
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;

	// HDC : ��¿� ���� ������ ���� �ִ� ������ ����ü
	// GDI�� �����ϸ� � ����Ʈ(��), ��(����, ����, ����)�� ���� ������ DC�� ����


	case WM_KEYDOWN:

		switch (wParam)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;
		}
		break;

	case WM_DESTROY:

		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// ���� ��ȭ ������ �޽��� ó�����Դϴ�.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

