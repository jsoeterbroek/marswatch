// ABOUTME: C source file for Darian calendar conversion functions.
// ABOUTME: Implements the logic for converting Earth dates to Mars dates.

#include "cal_darian.h"
#include <math.h>
#include <stdio.h>
#include <string.h>

// Darian calendar month names
const char* darian_month_names[] = {
    "Sagittarius", "Dhanus", "Capricornus", "Makara", "Aquarius", "Kumbha",
    "Pisces", "Mina", "Aries", "Mesha", "Taurus", "Vrishabha",
    "Gemini", "Mithuna", "Cancer", "Karka", "Leo", "Simha",
    "Virgo", "Kanya", "Libra", "Tula", "Scorpius", "Vrishika"
};

// Helper function to check for leap year in Darian calendar
int is_darian_leap_year(int year) {
    return (year % 2 != 0) || (year % 10 == 0 && year % 100 != 0) || (year % 500 == 0);
}

// Helper function to get the number of sols in a Darian month
int sols_in_darian_month(int year, int month) {
    if (month == 23 && is_darian_leap_year(year)) {
        return 28;
    }
    if ((month + 1) % 6 == 0) {
        return 27;
    }
    return 28;
}

void gregorian_to_darian(const struct tm* gregorian_date, Darian_Date* darian_date) {
    // Constants for calculation
    const double MIO_EPOCH = 2451545.0; // J2000.0 epoch
    const double MSD_EPOCH = 2405522.0; // Mars Sol Date epoch

    // Calculate Julian date from Gregorian date
    int a = (14 - (gregorian_date->tm_mon + 1)) / 12;
    int y = (gregorian_date->tm_year + 1900) + 4800 - a;
    int m = (gregorian_date->tm_mon + 1) + 12 * a - 3;
    double julian_date = gregorian_date->tm_mday + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;

    // Calculate Mars Sol Date
    double msd = (julian_date - MIO_EPOCH) / 1.02749125 + 44796.0 - 0.00096;

    // Calculate Darian date from MSD
    int year = (int)floor((msd - MSD_EPOCH) / 668.5991);
    double sol_of_year = fmod((msd - MSD_EPOCH), 668.5991);

    int month = 0;
    while (sol_of_year > sols_in_darian_month(year, month)) {
        sol_of_year -= sols_in_darian_month(year, month);
        month++;
    }

    darian_date->year = year;
    darian_date->month = month;
    darian_date->day = (int)floor(sol_of_year) + 1;
    strcpy(darian_date->month_name, darian_month_names[month]);
}
