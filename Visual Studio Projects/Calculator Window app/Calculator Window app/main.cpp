#include <Windows.h>

// 전역 변수 선언
HINSTANCE hInst;							// OS 객체(프로그램 실행을 관리)
LPCWSTR szTitle = L"Calculator";			
LPCWSTR szWindowClass = L"CalculatorClass";

// 함수 선언
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
ATOM MyRegisterClass(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE, int);

// WinMain 함수
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow) {
    MyRegisterClass(hInstance);
    if (!InitInstance(hInstance, nCmdShow)) {
        return FALSE;
    }

    MSG msg;

    // 메세지 루프 (GetMessage, Translate, DispatchMeesage 함수)
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}

// 창 클래스 등록 (윈도우의 템플릿)
ATOM MyRegisterClass(HINSTANCE hInstance) {
    WNDCLASSEXW wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = nullptr;
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);
    return RegisterClassExW(&wcex);
}

// 앱 초기화 (Init)
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow) {
    hInst = hInstance;
    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
    if (!hWnd) {
        return FALSE;
    }
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);
    return TRUE;
}