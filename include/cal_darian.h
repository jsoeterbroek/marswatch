// ABOUTME: Header file for Darian calendar conversion functions.
// ABOUTME: Provides declarations for converting Earth dates to Mars dates.

#ifndef CAL_DARIAN_H
#define CAL_DARIAN_H

#include <time.h>

typedef struct {
    int year;
    int month;
    int day;
    char month_name[20];
} Darian_Date;

void gregorian_to_darian(const struct tm* gregorian_date, Darian_Date* darian_date);

#endif // CAL_DARIAN_H
