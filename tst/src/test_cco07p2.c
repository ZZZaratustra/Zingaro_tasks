#include "test_cco07p2.h"
#include "cco07p2.h"

void test_cco07p2_case1(void) {
  int snowflakes[2][6] = {{0, 1, 2, 3, 4, 5}, {4, 5, 0, 1, 2, 3}};
  int actual = solve_snowflakes(snowflakes, 2);
  int expected = 1;

  TEST_ASSERT_EQUAL_INT(expected, actual);
  TEST_ASSERT_EQUAL_INT(expected, actual);
  TEST_ASSERT_EQUAL_INT(expected, actual);
}

void test_cco07p2_case2(void) {
  int snowflakes[2][6] = {{4, 5, 0, 1, 2, 3}, {5, 4, 3, 2, 1, 0}};
  int actual = solve_snowflakes(snowflakes, 2);
  int expected = 1;

  TEST_ASSERT_EQUAL_INT(expected, actual);
  TEST_ASSERT_EQUAL_INT(expected, actual);
  TEST_ASSERT_EQUAL_INT(expected, actual);
}

void test_cco07p2_case3(void) {
  int snowflakes[4][6] = {
      {4, 5, 0, 1, 2, 3},
      {5, 4, 3, 2, 1, 0},
      {0, 1, 2, 3, 4, 5},
      {1, 2, 3, 4, 5, 0},
  };
  int actual = solve_snowflakes(snowflakes, 4);
  int expected = 1;

  TEST_ASSERT_EQUAL_INT(expected, actual);
  TEST_ASSERT_EQUAL_INT(expected, actual);
  TEST_ASSERT_EQUAL_INT(expected, actual);
}

void test_solve_snowflakes(void) {
  puts("Тесты к задаче со снежинками");
  RUN_TEST(test_cco07p2_case1);
  RUN_TEST(test_cco07p2_case2);
  RUN_TEST(test_cco07p2_case3);
}
