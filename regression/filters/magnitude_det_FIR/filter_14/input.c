//flp30Equi

#include <dsverifier.h>

digital_system ds = {
    .b = {  -0.017042829284585,  -0.117502205578682,   0.010629734862364,   0.022239874084928,   0.021871516738035,  -0.012308178920559, -0.035634599438245,  -0.012326164120666,   0.035853369224973,   0.045361408266484,  -0.012470953961046,  -0.078664547861127, -0.051872585841923,   0.103369102442858,   0.298666347700426,   0.387501675793732,   0.298666347700426,   0.103369102442858, -0.051872585841923,  -0.078664547861127,  -0.012470953961046,   0.045361408266484,   0.035853369224973,  -0.012326164120666, -0.035634599438245,  -0.012308178920559,   0.021871516738035,   0.022239874084928,   0.010629734862364,  -0.117502205578682, -0.017042829284585  },
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
