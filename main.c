#include <stdio.h>
#include <windows.h>
#include "StudyTasks.h"
#pragma comment(lib, "StudyTasks.lib")

int main(void)
{
    double spent[]   = { 4.0, 10.0, 2.0 };
    double planned[] = { 8.0, 10.0, 4.0 };
    double week[]    = { 3, 5, 9, 4, 10, 2, 0 };

    SetConsoleOutputCP(CP_UTF8);
    printf("Пріоритет задачі: %.2f\n", CalcTaskPriority(2, 4, 30));
    printf("Прогрес: %.2f %%\n", CalcCourseProgress(spent, planned, 3));
    printf("Перевантажених днів: %d\n", CountOverloadedDays(week, 7, 8.0));
    return 0;
}
