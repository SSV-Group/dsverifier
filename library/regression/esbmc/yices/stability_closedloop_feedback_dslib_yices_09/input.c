#include "../../../../dsverifier.h"

digital_system control = {
        .a = { 1.0f, 0.4f, -0.19f, 0.014f, 0.0f},
        .a_size = 5,
        .b = {0.15f, -0.075f, -0.051f, 0.012f},
        .b_size = 4,
        .sample_time = 0.01
};

implementation impl = {
        .int_bits = 3,
        .frac_bits = 16,
        .delta = 0.25,
        .max = 1.0,
        .min = -1.0,
        .scale = 1
};

digital_system plant = {
        .b = { 2.0f, -4.0f },
        .b_size = 2,
        .a = { 1.0f, -0.1f,  -0.3f },
        .a_size = 3
};
