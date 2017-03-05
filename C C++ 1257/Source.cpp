#include <Windows.h>
/*#include "generic.h"
#if defined (win32)*/

HINSTANCE hInst;
LPCTSTR lpszAppName = "Generic";
LPCTSTR lpszTitle = "Generic Application";
BOOL RegisterWin95(CONST WNDCLASS* lpwc);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	MSG msg;
	HWND hWnd;
	WNDCLASS wc;

	wc.style = CS_HREDRAW | CS_VREDRAW ;
	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = 0;
	wc.hIcon = LoadIcon(hInstance, lpszAppName);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH) (COLOR_WINDOW +1 );
	wc.lpszMenuName = lpszAppName;
	wc.lpszClassName = lpszAppName;

	if(!RegisterWin95(&wc)){
		return false;
	}

	hInst = hInstance;
	hWnd = CreateWindow(lpszAppName,
						lpszTitle,
						WS_OVERLAPPEDWINDOW,
						CW_USEDEFAULT, 0,
						CW_USEDEFAULT, 0,
						NULL,
						NULL,
						hInstance,
						NULL);

	if(!hWnd)
		return false;

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	while(GetMessage(&msg, NULL, 0, 0)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (msg.wParam);
}//continuat jamsa pg 978


