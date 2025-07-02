#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "cal_darian.h"
#include "doctest.h"

// https://interimm.org/mars-clock/en/
// TEST_CASE("Darian (Mars) calendar date conversion and formatting") {
//   double jd = gregorian_to_jd(2025, 5, 20);
//   int darian_year, darian_month, sol;
//   jd_to_darian(jd, darian_year, darian_month, sol);
// }

/*
Some important dates in the Darian calendar (Source:
https://en.wikipedia.org/wiki/Darian_calendar)
*/

// Mariner 4 flyby: 15 July 1965 = 26 Taurus 189 in Darian calendar
TEST_CASE("Mariner 4 flyby date conversion") {
  struct tm gregorian_date = {0};
  gregorian_date.tm_year = 1965 - 1900;
  gregorian_date.tm_mon = 7 - 1;
  gregorian_date.tm_mday = 15;

  Darian_Date darian_date;
  gregorian_to_darian(&gregorian_date, &darian_date);

  CHECK(darian_date.year == "189");
  CHECK(darian_date.month_name == "Taurus");
  CHECK(darian_date.day == 26);
}

// // Perseverance landing: 18 February 2021  = 13 Sagittarius 219 in Darian
// calendar
TEST_CASE("Perseverance landing date conversion") {}
