#include <dsverifier.h>

digital_system controller = { 
	.b = {  -148496.8672 , 709359.0499 , -1206938.2888 , 585624.4263 , 736818.4369 , -1176777.3022 , 618616.7188 , -118206.1742 },
	.b_uncertainty = {  0.05 , 0.05 , 0.05 , 0.05 , 0.05 , 0.05 , 0.05 , 0.05 },
	.b_size =  8,
	.a = {  1 , -5.7481 , 14.0904 , -19.0956 , 15.4509 , -7.4608 , 1.9882 , -0.22492 },
	.a_uncertainty = {  0.05 , 0.05 , 0.05 , 0.05 , 0.05 , 0.05 , 0.05 , 0.05 },
	.a_size =  8,
	.sample_time = 1.000000e-03
};

implementation impl = { 
	.int_bits =  23,
	.frac_bits =   8,
	.max =  1.000000,
	.min =  -1.000000
	};

digital_system plant = { 
	.b = {  -4.4375e-09 , -1.3312e-08 , -1.3312e-08 , -4.4375e-09 },
	.b_uncertainty = {  0.05 , 0.05 , 0.05 , 0.05 },
	.b_size =  4,
	.a = {  1 , -2.9598 , 2.9149 , -0.95533 },
	.a_size =  4 
	.a_uncertainty = {  0.05 , 0.05 , 0.05 , 0.05 },
	};

