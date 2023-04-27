/*
* A command line program to convert between temps
*   in Fahrenheit & Celsius.
*
* Author: Daniel M. Anderson
*         4/27/23
*
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <getopt.h>

static double fahrenheit_to_celsius(float f)
{
    return (5.0 / 9.0) * (f - 32.0);
}

static double celsius_to_fahrenheit(float c)
{
    return (c * (9.0 / 5.0)) + 32.0;
}

int main(int argc, char **argv)
{
    int opt, opterr = 0; 
    bool f_flag, c_flag, h_flag = false;
    double input = 0.0;

    while ((opt = getopt(argc, argv, "f:c:h")) != -1) {
        switch (opt) {
            case 'h' :
                h_flag = true;
                break;
            case 'f' :
                f_flag = true;
                input = atof(optarg);
                break;
            case 'c' :
                c_flag = true;
                input = atof(optarg);
                break;
            case '?' :
                fprintf(stderr, "Unrecognized argument, arg was '%i'\n", opt);
                return 1;
        }
    }
    // Help flag, print help information and terminate
    if (h_flag) {
        printf("f2c -- Convert temperature values between Celsius and Fahrenheit.\n");
        printf("Example usage: Convert 72 degrees Fahrenheit to Celsius.\n");
        printf("$ f2c -f 72\n>   22.2222\n");
        return 1;
    }

    if (!f_flag && !c_flag) {
        fprintf(stderr, "Expected one of '-c' or '-f' to be present, found neither!\n");
        return 1;
    }

    if (f_flag && c_flag) {
        fprintf(stderr, "Expected only one of '-c' or '-f' to be present, found both!\n");
        return 1;
    }

    if (f_flag) {
        printf("%f\n", fahrenheit_to_celsius(input));
        return 0;
    } else if (c_flag) {
        printf("%f\n", celsius_to_fahrenheit(input));
        return 0;
    }

    // Fallthrough
    return 1;
}

