//fhp10Hann

#include <dsverifier.h>

digital_system ds = {
    .b =  {    0,   0.007252085499649,   0.021621541541142,  -0.061440654310311,  -0.274770959239840,   0.602078302223927, -0.274770959239840,  -0.061440654310311,   0.021621541541142,   0.007252085499649,  0},
    .b_size = 11,
    .a = {1.0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    .a_size = 11
};

filter_parameters filter = {
    .Ap =  0.8,
    .Ac =  0.707945784384138,
    .Ar = 0.5,
    .wp = 0.5,
    .wc = 0.4,
    .wr = 0.3,
    .type = 2
};

implementation impl = {
    .int_bits = 4,
    .frac_bits = 10,
    .min = -1.6,
    .max = 1.6,
};
