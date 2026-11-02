#ifndef STUDYTASKS_H
#define STUDYTASKS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Пріоритет задачі: 0..100, -1 при помилці */
double __stdcall CalcTaskPriority(int daysLeft,
                                  int difficulty,
                                  int weightPercent);

/* Прогрес виконання, %: 0..100, -1 при помилці */
double __stdcall CalcCourseProgress(const double *spentHours,
                                    const double *plannedHours,
                                    int count);

/* Кількість днів із перевищенням ліміту; -1 при помилці */
int __stdcall CountOverloadedDays(const double *hoursPerDay,
                                  int days,
                                  double maxHoursPerDay);

#ifdef __cplusplus
}
#endif

#endif /* STUDYTASKS_H */
