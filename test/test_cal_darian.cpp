
/*
Some important dates in the Darian calendar (Source: https://en.wikipedia.org/wiki/Darian_calendar):

+----------------------+-------------------+--------------------+-----------------+---------------+
| Event                | Gregorian date    | Darian date        | Mars Julian Sol | Mars Sol Date |
+----------------------+-------------------+--------------------+-----------------+---------------+
| Mariner 4 flyby      | 15 July 1965      | 26 Taurus 189      | 126668          | 32539         |
| Viking 1 landing     | 20 July 1976      | 14 Mina 195        | 130584          | 36455         |
| Viking 2 landing     | 3 September 1976  | 3 Mesha 195        | 130629          | 36500         |
| Perseverance landing | 18 February 2021  | 13 Sagittarius 219 | 146433          | 52304         |
+----------------------+-------------------+--------------------+-----------------+---------------+
*/

#include <unity.h>
#include "cal_darian.h"

// Mariner 4 flyby: 15 July 1965 = 26 Taurus 189 in Darian calendar
void test_mariner_4_flyby_date_conversion() {
    struct tm gregorian_date = {0};
    gregorian_date.tm_year = 1965 - 1900;
    gregorian_date.tm_mon = 7 - 1;
    gregorian_date.tm_mday = 15;

    Darian_Date darian_date;
    gregorian_to_darian(&gregorian_date, &darian_date);

    TEST_ASSERT_EQUAL_INT(189, darian_date.year);
    TEST_ASSERT_EQUAL_STRING("Taurus", darian_date.month_name);
    TEST_ASSERT_EQUAL_INT(26, darian_date.day);
}

// // Perseverance landing: 18 February 2021  = 13 Sagittarius 219 in Darian calendar
void test_perseverance_landing_date_conversion() {
    struct tm gregorian_date = {0};
    gregorian_date.tm_year = 2021 - 1900;
    gregorian_date.tm_mon = 2 - 1;
    gregorian_date.tm_mday = 18;

    Darian_Date darian_date;
    gregorian_to_darian(&gregorian_date, &darian_date);

    TEST_ASSERT_EQUAL_INT(219, darian_date.year);
    TEST_ASSERT_EQUAL_STRING("Sagittarius", darian_date.month_name);
    TEST_ASSERT_EQUAL_INT(13, darian_date.day);
}

void setUp(void) {
    // set up to run before each test
}

void tearDown(void) {
    // clean up after each test
}

int main(int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_mariner_4_flyby_date_conversion);
    RUN_TEST(test_perseverance_landing_date_conversion);
    UNITY_END();
    return 0;
}
