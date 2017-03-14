//flp30

#include <dsverifier.h>

digital_system ds = {
    .b = {   -0.000000000000000,  -0.021071823591856,  -0.014129841884859,   0.015412994098398,   0.027378069951347,  -0.000000000000000, -0.033829631930845,  -0.023630382158790,   0.027116347128577,   0.051368330061880,  -0.000000000000000,  -0.077470282088069, -0.063959743655276,   0.096069065527552,   0.311137510336824,   0.411218776410233,   0.311137510336824,   0.096069065527552, -0.063959743655276,  -0.077470282088069,  -0.000000000000000,   0.051368330061880,   0.027116347128577,  -0.023630382158790, -0.033829631930845,  -0.000000000000000,   0.027378069951347,   0.015412994098398,  -0.014129841884859,  -0.021071823591856, -0.000000000000000},
    .b_size = 31,
    .a = {1.0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    .a_size = 31
};

filter_parameters filter = {
    .Ap =  0.8,
    .Ac =  0.707945784384138,
    .Ar = 0.5,
    .wp = 0.3,
    .wc = 0.4,
    .wr = 0.5,
    .type = 1
};

implementation impl = {
    .int_bits = 4,
    .frac_bits = 10,
    .min = -1.6,
    .max = 1.6,
};
