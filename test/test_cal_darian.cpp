#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "cal_darian.h"
#include "doctest.h"

// Mariner 4 flyby: 15 July 1965 = 26 Taurus 189 in Darian calendar
TEST_CASE("Mariner 4 flyby date conversion") {
  struct tm gregorian_date = {0};
  gregorian_date.tm_year = 1965 - 1900;
  gregorian_date.tm_mon = 7 - 1;
  gregorian_date.tm_mday = 15;

  Darian_Date darian_date;
  gregorian_to_darian(&gregorian_date, &darian_date);

  CHECK(darian_date.year == 189);
  CHECK(strcmp(darian_date.month_name, "Taurus") == 0);
  CHECK(darian_date.day == 26);
}

// Perseverance landing: 18 February 2021  = 13 Sagittarius 219 in Darian
// calendar
TEST_CASE("Perseverance landing date conversion") {
  struct tm gregorian_date = {0};
  gregorian_date.tm_year = 2021 - 1900;
  gregorian_date.tm_mon = 2 - 1;
  gregorian_date.tm_mday = 18;

  Darian_Date darian_date;
  gregorian_to_darian(&gregorian_date, &darian_date);

  CHECK(darian_date.year == 219);
  CHECK(strcmp(darian_date.month_name, "Sagittarius") == 0);
  CHECK(darian_date.day == 13);
}
