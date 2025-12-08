#include "test_lkp18c2p1.h"

void test_solve_case1(void) 
{
    int lines[] = {2, 1, 0};
    int expected[] = {3, 3, 2}; 
    solve(lines, 3, 5);

    TEST_ASSERT_EQUAL_INT(expected[0], lines[0]);
    TEST_ASSERT_EQUAL_INT(expected[1], lines[1]);
    TEST_ASSERT_EQUAL_INT(expected[2], lines[2]);
}

void test_solve_case2(void) 
{
    int lines[] = {0, 0, 0};
    int expected[] = {2, 2, 1}; 
    solve(lines, 3, 5);

    TEST_ASSERT_EQUAL_INT(expected[0], lines[0]);
    TEST_ASSERT_EQUAL_INT(expected[1], lines[1]);
    TEST_ASSERT_EQUAL_INT(expected[2], lines[2]);
}

void test_solve_case3(void) 
{
    int lines[100] = {0};
    int expected[] = {1, 1, 1, 1, 1};  
    solve(lines, 100, 5);

    TEST_ASSERT_EQUAL_INT(expected[0], lines[0]);
    TEST_ASSERT_EQUAL_INT(expected[1], lines[1]);
    TEST_ASSERT_EQUAL_INT(expected[2], lines[2]);
    TEST_ASSERT_EQUAL_INT(expected[2], lines[2]);
    TEST_ASSERT_EQUAL_INT(expected[2], lines[2]);
}

void test_solve_all(void) {
    puts("Тесты к задаче очереди в магазине");
    RUN_TEST(test_solve_case1);
    RUN_TEST(test_solve_case2);
    RUN_TEST(test_solve_case3);
}
