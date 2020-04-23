// This header contain the "algorithms.c", "data_structures.c" and "test.c" methods declarations, and 
// the macro definitions used by them.
// A header file is a file containing C declarations and macro definitions (see Macros) to be 
// shared between several source files. You request the use of a header file in your program by 
// including it, with the C preprocessing directive ‘#include’.
// From: https://gcc.gnu.org/onlinedocs/cpp/Header-Files.html

#ifndef DATA_STRUCTURES_H // #ifndef and #define are called #include guards.
#define DATA_STRUCTURES_H // They prevents double declaration of any identifiers such as types, enums and static variables.

#define PI 3.14159265358979323846

// algorithms.c
unsigned int factorial(unsigned int n);
double sine_taylor(double x, double n);
unsigned int fibonacci(unsigned int n);
int binomial_coefficient(int n, int k);
int min(int a, int b);

// test.c
double get_value(char *value_name);
void func_head(char *func, char *quit_v, char *quit_n);
void test_sine();
void test_fibo();
void test_bc();
void pascal_triangle();

#endif