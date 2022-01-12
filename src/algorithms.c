// This code contains some known algorithms.

#include "data_structures.h"

// Factorial calculus algorithm. Returns n!
unsigned int factorial(unsigned int n) {
	unsigned int i, f = 1;
	for(i = 2; i <= n; i++) f *= i; // Produtório do fatorial
	return f;
}

// Algorithm for calculating sin(x) by a computer.
// Uses the formula: sin(x,N) = x * ( 1 - (x^2)/(2*3) * ( 1 - (x^2)/(4*5) * ...))
// Definition of t(i-1): t(i-1) = 1 - (x^2)/( 2i*(2i+1) ) * T(i)
// Parameters:
// 		x: abscissa value
// 		n: precision (the bigger, the more accurate)
double sine_taylor(double x, double n) {
	unsigned int i; double t = 1.0;
	for(i = n; i > 0; i--) t = 1 - x*x / (2*i * (2*i+1)) * t;
	return x*t;
}

// Fibonnaci sequence (0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...)
// In the fibonacci sequence, the nth number is the sum of its two predecessors, that is, f(n) = f(n-1) + f(n-2).
// Parameter:
// 		n: the nth fibonacci number
unsigned int fibonacci(unsigned int n) {
	unsigned int i, preview = 0, actual = 1, next;
	if(n < 2) return n;
	for(i = 2; i <= n; i++) {
		next = actual + preview;
		preview = actual;
		actual = next;
	}
	return next;
}

// Binomial Coefficient
// Used for Pascal's Triangle and Combination (there are C(n, k) ways to choose k elements from a set of n elements)
// C(n, k) = n! / ( k! * (n-k)! )
// This algorithms uses Dynamic Programming (usage of memory for store subproblems solutions) to avoid
// re-computations of subproblems, by constructing a auxiliary array C[][].
int binomial_coefficient(int n, int k) {
	int C[n+1][k+1];
	int i, j;
	for(i = 0; i <= n; i++) {
		for(j = 0; j <= min(i, k); j++) {
			if(j == 0 || j == i) C[i][j] = 1;
			else C[i][j] = C[i-1][j-1] + C[i-1][j];
		}
	}
	return C[n][k];
}
// Auxiliary function to return the smaller of two integers
int min(int a, int b) { return (a < b) ? a : b; }