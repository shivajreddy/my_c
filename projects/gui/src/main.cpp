#include <corecrt_wstdlib.h> // ori
#include <cstdlib>           // ori
#include <float.h>           // ori
#include <format>            // ori
#include <windows.h>         // ori
#include <wingdi.h>          // ori
#include <winuser.h>         // ori

// Defining more meaningful aliases for 'static'
#define LOCAL_PERSIST static
#define INTERNAL_FN static
#define GLOBAL_VAR static

//-------------------------------------------------------------------
// GLOBAL VARIABLES
//-------------------------------------------------------------------
#define PROJECT_NAME "gui"
HINSTANCE global_hInstance;
char win_title[100];
char win_class[100];

GLOBAL_VAR bool IsRunning = false;

// Double buffering variables
GLOBAL_VAR HDC memDC = NULL;
GLOBAL_VAR HBITMAP memBitmap = NULL;
GLOBAL_VAR HBITMAP oldBitmap = NULL;
GLOBAL_VAR int bufferWidth = 0;
GLOBAL_VAR int bufferHeight = 0;

//-------------------------------------------------------------------
// FORWARD DECLARATIONS
//-------------------------------------------------------------------
ATOM RegisterMainWindowClass(HINSTANCE);
LRESULT CALLBACK MainWindowCallbackProcedure(HWND, UINT, WPARAM, LPARAM);
BOOL InitializeWindowInstance(HINSTANCE, int);

//-------------------------------------------------------------------
// APP ENTRY POINT
//-------------------------------------------------------------------
int APIENTRY wWinMain(_In_ HINSTANCE Instance, _In_opt_ HINSTANCE PrevInstance,
                      _In_ LPWSTR CommandLine, _In_ int ShowCommand) {
    strcpy_s(win_title, PROJECT_NAME);
    strcpy_s(win_class, PROJECT_NAME);

    RegisterMainWindowClass(Instance);

    if (!InitializeWindowInstance(Instance, ShowCommand)) return FALSE;
    OutputDebugStringA("Main Window Created\n");

    IsRunning = true;

    MSG Message;
    HACCEL hAccelTable = LoadAccelerators(Instance, MAKEINTRESOURCE(109));
    while (IsRunning) {
        BOOL MessageResult = GetMessage(&Message, 0, 0, 0);
        if (MessageResult > 0) {
            TranslateMessage(&Message);
            DispatchMessage(&Message);
        } else
            break;
    }

    // Clean up
    if (memDC) {
        if (oldBitmap) SelectObject(memDC, oldBitmap);
        if (memBitmap) DeleteObject(memBitmap);
        DeleteDC(memDC);
    }

    return EXIT_SUCCESS;
}

BOOL InitializeWindowInstance(HINSTANCE Instance, int ShowCommand) {
    global_hInstance = Instance;

    HWND WindowHandle = CreateWindowEx(
        0, win_class, win_title, WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, 0, 0, Instance, 0);

    if (!WindowHandle) return FALSE;

    return TRUE;
}

ATOM RegisterMainWindowClass(HINSTANCE hInst) {
    WNDCLASS WindowClass = { 0 };
    WindowClass.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
    WindowClass.lpfnWndProc = MainWindowCallbackProcedure;
    WindowClass.hInstance = hInst;
    WindowClass.lpszClassName = win_class;

    return RegisterClass(&WindowClass);
}

const int rect_brush_w = 30;
const int rect_brush_h = 20;
void handle_paint(HWND);

void CreateBackBuffer(HWND hwnd, int width, int height) {
    // Clean up old buffer
    if (memDC) {
        if (oldBitmap) SelectObject(memDC, oldBitmap);
        if (memBitmap) DeleteObject(memBitmap);
        DeleteDC(memDC);
    }

    // Create new buffer
    HDC hdc = GetDC(hwnd);
    memDC = CreateCompatibleDC(hdc);
    memBitmap = CreateCompatibleBitmap(hdc, width, height);
    oldBitmap = (HBITMAP)SelectObject(memDC, memBitmap);
    ReleaseDC(hwnd, hdc);

    bufferWidth = width;
    bufferHeight = height;

    // Fill with white background
    RECT rect = { 0, 0, width, height };
    FillRect(memDC, &rect, (HBRUSH)(COLOR_WINDOW + 1));
}

void DrawToBackBuffer(int x, int y) {
    if (!memDC) return;

    // Draw directly to the back buffer
    HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0));
    HBRUSH oldBrush = (HBRUSH)SelectObject(memDC, brush);
    HPEN pen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
    HPEN oldPen = (HPEN)SelectObject(memDC, pen);

    Rectangle(memDC, x, y, x + rect_brush_w, y + rect_brush_h);

    SelectObject(memDC, oldPen);
    SelectObject(memDC, oldBrush);
    DeleteObject(pen);
    DeleteObject(brush);
}

void ClearBackBuffer() {
    if (!memDC) return;
    RECT rect = { 0, 0, bufferWidth, bufferHeight };
    FillRect(memDC, &rect, (HBRUSH)(COLOR_WINDOW + 1));
}

bool app_is_active = false;
bool isDrawing = false;
LRESULT CALLBACK MainWindowCallbackProcedure(HWND Window, UINT Message,
                                             WPARAM WParam, LPARAM LParam) {
    LRESULT result = 0;

    switch (Message) {
    case WM_CREATE: {
        // Initialize back buffer on window creation
        RECT ClientRect;
        GetClientRect(Window, &ClientRect);
        int width = ClientRect.right - ClientRect.left;
        int height = ClientRect.bottom - ClientRect.top;
        CreateBackBuffer(Window, width, height);
    } break;
    case WM_KEYDOWN: {
        if (WParam == 'X') {
            ClearBackBuffer();
            InvalidateRect(Window, NULL, TRUE);
        }
    } break;
    case WM_SIZE: {
        RECT ClientRect;
        GetClientRect(Window, &ClientRect);
        int width = ClientRect.right - ClientRect.left;
        int height = ClientRect.bottom - ClientRect.top;

        CreateBackBuffer(Window, width, height);
        InvalidateRect(Window, NULL, TRUE);
        OutputDebugStringA("WM_SIZE invoked cuz resized\n");
    } break;
    case WM_DESTROY: {
        OutputDebugStringA("WM_DESTROY-Window is destroyed\n");
        IsRunning = false;
    } break;
    case WM_CLOSE: {
        OutputDebugStringA("WM_CLOSE-Window is closed\n");
        IsRunning = false;
    } break;
    case WM_ACTIVATEAPP: {
        app_is_active = !app_is_active;
        std::string msg = std::format("Main window is {}\n", app_is_active);
        OutputDebugStringA(msg.c_str());
    } break;
    case WM_PAINT: {
        handle_paint(Window);
    } break;
    case WM_LBUTTONDOWN: {
        isDrawing = true;
        SetCapture(Window);
        int x = LOWORD(LParam);
        int y = HIWORD(LParam);
        DrawToBackBuffer(x, y);
        InvalidateRect(Window, NULL, FALSE);
    } break;
    case WM_LBUTTONUP: {
        isDrawing = false;
        ReleaseCapture();
    } break;
    case WM_MOUSEMOVE: {
        if (isDrawing) {
            int x = LOWORD(LParam);
            int y = HIWORD(LParam);
            DrawToBackBuffer(x, y);
            InvalidateRect(Window, NULL, FALSE);
        }
    } break;
    default: { // for all unhandled message types, use default procedures
        result = DefWindowProc(Window, Message, WParam, LParam);
    } break;
    };
    return result;
};

void handle_paint(HWND hwnd) {
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hwnd, &ps);

    if (memDC) {
        // Blit the back buffer to the screen
        BitBlt(hdc, 0, 0, bufferWidth, bufferHeight, memDC, 0, 0, SRCCOPY);
    }

    EndPaint(hwnd, &ps);
}
