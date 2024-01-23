// Editor_Window.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "Editor_Window.h"
#include "CommonInclude.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, // 프로그램 인스턴스 핸들
                     _In_opt_ HINSTANCE hPrevInstance, // 바로 앞에 실행된 현재 프로그램의 인스턴스 핸들, 없을 경우 NULL
                                                       // 지금은 신경쓰지 않아도 되는 값이다.
                     _In_ LPWSTR    lpCmdLine,  // 명령행 으로 입력된 프로그램 인수 (Args) - 거의 쓸 일 x
                     _In_ int       nCmdShow) // 프로그램이 실행될 형태이며, 보통 모양정보 등이 전달된다.
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);


    // 깃허브 테스트

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_EDITORWINDOW, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance); // 윈도우 정보 할당

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow)) // 윈도우 생성, show
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_EDITORWINDOW));

    MSG msg;

    // Main message loop:
    // 프로그램 종료되지 않도록 계속 루프
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_EDITORWINDOW));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_EDITORWINDOW);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
    
    // 메모리에 '윈도우 정보' 할당 (이름: szWindowClass)
    return RegisterClassExW(&wcex); 
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   // szWindowClass : 아까 메모리에 넣은 윈도우 정보
   // CreateWindowW : 실제 윈도우 인스턴스 - 메모리 할당
   // hWnd : 윈도우 인스턴스에 대한 핸들 값 반환
   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, 1600, 900, nullptr, nullptr, hInstance, nullptr);

   //2개 이상의 윈도우도 생성 가능하다.
   //HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
   //    CW_USEDEFAULT, 0, 1600, 900, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }


   ShowWindow(hWnd, nCmdShow); // 윈도우 화면 출력
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window. - 메시지 처리
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
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
    case WM_PAINT:
        {
            //DC : 화면 출력에 필요한 모든 정보를 가지는 데이터 구조체.
            // - GDI모듈에 의해 관리 된다.
            // - 폰트 / 선의 굵기 / 색상 : '그림' 정보
            // - WinAPI에서 화면 출력에 필요한 모든 경우는 DC를 통해서 진행.
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);

            // 파랑 브러쉬 생성
            HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));
            // 파랑 브러쉬 DC에 선택 & 흰색(default) 브러쉬 반환
            HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

            Rectangle(hdc, 100, 100, 200, 200);

            // 다시 흰색 원본브러쉬 선택
            SelectObject(hdc, oldBrush);
            // 파랑 브러쉬 삭제
            DeleteObject(brush);

            HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
            HPEN oldPen = (HPEN)SelectObject(hdc, redPen);

            Ellipse(hdc, 200, 200, 300, 300);

            SelectObject(hdc, oldPen);
            DeleteObject(redPen);

            // 기본으로 자주 사용되는 GDI 오브젝트를 미리 DC안에 만들어두었는데,
            // 그 오브젝트들을 '스톡 오브젝트' 라고 한다.
            HBRUSH grayBrush = (HBRUSH)GetStockObject(GRAY_BRUSH);
            oldBrush = (HBRUSH)SelectObject(hdc, grayBrush);
            Rectangle(hdc, 400, 400, 500, 500);
            SelectObject(hdc, oldBrush); // 쓰고나면 항상 default로!

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    //case WM_LBUTTONDOWN:
    //    DestroyWindow(hWnd);
    //    break;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
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
