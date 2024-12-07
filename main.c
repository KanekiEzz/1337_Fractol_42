#include "./includes/fractol.h"

int main ()
{
    t_complex   z;
    //  point
    t_complex c;
    double tmp_real;

    z.real = 0;
    z.im = 0;

    c.real = 0.25;
    c.im = 0.4;

    int i = 0;
    while(i < 42)
    {
        // General formula
        // z = z^2 + c
        tmp_real = (z.real * z.real) - (z.im * z.im); //  + c.real
        z.im = 2 * z.real * z.im;
        z.real = tmp_real;

        // Adding the c value
        z.real += c.real;
        z.im += c.im;

        printf("iteration n -> %d real %f imaginary %f\n", i, z.real, z.im);
        ++i;
    }
}