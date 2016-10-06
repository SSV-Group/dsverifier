function [output, time_execution] = dsv_check_overflow(system)
%
% Script developed to check overflow automatically all counterexamples 
% by realization form (DFI, DFII and TDFII)
%
% Give the system as a struct with all parameters of counterexample and
% simulate the system.
% Based on overflowtest.m function
% 
% Lennon Chaves
% September 29, 2016
% Manaus

tic

a = system.sys.a;
b = system.sys.b;
u = system.inputs.const_inputs;
delta = system.impl.delta;
l = system.impl.frac_bits;
n = l + system.impl.int_bits - 1;

if delta > 0
    [at,bt]=deltapoly(b,a,delta);
else
    at=a;
    bt=b;
end
uf=(2^(l))*u;

y=dlsim(bt,at,uf);
min = -1*((2^n));
max = ((2^n)-1);

for i=1:length(y)
    if (y(i)> max) || (y(i)< min)
        result=1;
        %'An overflow occurred'
        break;
    else
 	%'There were no overflow');
        result=0;
    end
end

if result == 1
    output = 'Failed';
else
    output = 'Successfull';
end

 
time_execution = toc;
end
