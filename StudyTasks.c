#include <windows.h>
#include "StudyTasks.h"

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason,
                    LPVOID lpvReserved)
{
    (void)lpvReserved;
    switch (fdwReason)
    {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hinstDLL);
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

/* Підзадача 1. Розрахунок пріоритету навчальної задачі.
   urgency = 1 / (1 + daysLeft / 3), для прострочених = 1.
   priority = 100 * (0.5*urgency + 0.3*weight/100 + 0.2*difficulty/5) */
double __stdcall CalcTaskPriority(int daysLeft, int difficulty,
                                  int weightPercent)
{
    double urgency;

    if (difficulty < 1 || difficulty > 5 ||
        weightPercent < 1 || weightPercent > 100)
        return -1.0;

    if (daysLeft <= 0)
        urgency = 1.0;
    else
        urgency = 1.0 / (1.0 + daysLeft / 3.0);

    return 100.0 * (0.5 * urgency
                  + 0.3 * (weightPercent / 100.0)
                  + 0.2 * (difficulty / 5.0));
}

/* Підзадача 2. Загальний прогрес виконання задач, %.
   Внесок кожної задачі обмежується її плановими годинами. */
double __stdcall CalcCourseProgress(const double *spentHours,
                                    const double *plannedHours,
                                    int count)
{
    int i;
    double done = 0.0, total = 0.0;

    if (spentHours == NULL || plannedHours == NULL || count <= 0)
        return -1.0;

    for (i = 0; i < count; i++)
    {
        if (spentHours[i] < 0.0 || plannedHours[i] <= 0.0)
            return -1.0;
        done += (spentHours[i] < plannedHours[i])
                    ? spentHours[i] : plannedHours[i];
        total += plannedHours[i];
    }
    return done / total * 100.0;
}

/* Підзадача 3. Контроль навантаження: кількість днів,
   у яких заплановані години перевищують ліміт. */
int __stdcall CountOverloadedDays(const double *hoursPerDay,
                                  int days, double maxHoursPerDay)
{
    int i, result = 0;

    if (hoursPerDay == NULL || days <= 0 || maxHoursPerDay <= 0.0)
        return -1;

    for (i = 0; i < days; i++)
        if (hoursPerDay[i] > maxHoursPerDay)
            result++;
    return result;
}
