//lp12EST(6)

#include <dsverifier.h>

digital_system ds = {
            .b =  { 7.120601713134334e-03   ,  1.734723475976807e-18  ,  -2.429729818092206e-02  , -6.938893903907228e-18 ,    4.613413371939577e-02   ,    0  ,  -5.613064430953354e-02  ,      0   ,  4.613413371939578e-02  ,  -6.938893903907228e-18  ,  -2.429729818092206e-02   ,  1.734723475976807e-18  ,   7.120601713134334e-03},
            .b_size = 13,
            .a =  {1.000000000000000e+00  ,   4.440892098500626e-16  ,   2.744557705156605e+00  ,  -1.110223024625157e-15   ,  4.495158480897365e+00  ,  -4.440892098500626e-15  ,   4.649204375147078e+00   , -5.773159728050814e-15    , 3.229978425883890e+00   , -3.774758283725532e-15 ,    1.408884264809281e+00  ,  -1.221245327087672e-15   ,  3.145186828647423e-01},
            .a_size = 13
         };

implementation impl = {
         .int_bits = 5,
         .frac_bits = 10,
         .min = -1.6,
         .max = 1.6,
};


filter_parameters filter = {
        .Ap = 0.891250938133746, 
        .Ar = 0.891250938133746,

         .w1p = 0.3,
         .w2p = 0.7,

         .w1r = 0.29,
         .w2r = 0.71,

        // .1st_wr = 0.29,
        // .2nd_wr = 0.71,

         .type = 3
};