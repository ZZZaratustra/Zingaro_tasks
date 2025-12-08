// #include "lkp18c2p1.h"
#include <locale.h>
#include "type.h"
#include <windows.h>
#include "test_lkp18c2p1.h"

void setUp(void) {
}

void tearDown(void) {
}

int main(int argc, char* argv[])
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    if (argc > 1) {
        if (!strcmp(argv[1], "--test")) {
            UNITY_BEGIN();
            test_solve_all();
            return UNITY_END();
        }
    } else {
        puts("[0]");
        return 0;
    }

}