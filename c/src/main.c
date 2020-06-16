#include "clock_test.h"
#include "multiplication_simple_test.h"
#include "multiplication_basic_test.h"
#include "multiplication_tiling_test.h"
#include "multiplication_tiling_outer_test.h"
#include "multiplication_basic_tiling_test.h"
#include "flops_basic_test.h"
#include "flops_tiling_test.h"
#include "flops_tiling_block_test.h"
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(0));
    // graph with flops comparison maybe use python

    // multiplication_simple_test();
    // small_time_test();
    // multiplication_basic_test();
    // multiplication_tiling_test();
    // multiplication_tiling_outer_test();
    // multiplication_basic_tiling_test();
    // flops_basic_test();
    // flops_tiling_test();
    flops_tiling_block_test();

    return 0;
}
