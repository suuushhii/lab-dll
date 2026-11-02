#include <stdio.h>
#include <windows.h>

typedef double (__stdcall *PRIORITY_FN)(int, int, int);

int main(void)
{
    HMODULE hLib;
    PRIORITY_FN pPriority;

    SetConsoleOutputCP(CP_UTF8);
    hLib = LoadLibraryA("StudyTasks.dll");
    if (hLib == NULL)
    {
        printf("Помилка завантаження DLL: %lu\n", GetLastError());
        return 1;
    }
    pPriority = (PRIORITY_FN)GetProcAddress(hLib, "CalcTaskPriority");
    if (pPriority != NULL)
        printf("Пріоритет задачі: %.2f\n", pPriority(2, 4, 30));
    else
        printf("Функцію не знайдено\n");
    FreeLibrary(hLib);
    return 0;
}
