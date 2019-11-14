#include "clock_test.h"
#include "multiplication_basic_test.h"
#include "multiplication_tiling_test.h"
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(0));

    small_time_test();
    multiplication_basic_test();
    multiplication_tiling_test();

    return 0;
}
