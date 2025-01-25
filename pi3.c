#include <stdio.h>
#include <gmp.h>

void calculate_pi(mpf_t pi, int iterations) {
    // Set up variables
    mpf_t K, M, X, L, S, term, temp;
    mpf_inits(K, M, X, L, S, term, temp, NULL);

    // Constants
    mpf_set_ui(K, 6);          // K = 6
    mpf_set_ui(M, 1);          // M = 1
    mpf_set_ui(X, 1);          // X = 1
    mpf_set_ui(L, 13591409);   // L = 13591409
    mpf_set_ui(S, 13591409);   // S = 13591409 (first term of series)
    
    mpf_t sixteen;             // For 16^(-k)
    mpf_init_set_ui(sixteen, 16);

    // Iterate to compute terms of the series
    for (int k = 1; k <= iterations; k++) {
        // Update M
        mpf_mul_ui(M, M, 6 * k - 5);    // M *= (6k - 5)
        mpf_mul_ui(M, M, 2 * k - 1);    // M *= (2k - 1)
        mpf_mul_ui(M, M, 6 * k - 1);    // M *= (6k - 1)
        mpf_div_ui(M, M, k * k * k);    // M /= k^3

        // Update L
        mpf_add_ui(L, L, 545140134);    // L += 545140134

        // Update X
        mpf_mul_ui(X, X, 262537412640768000); // X *= (-640320)^3 = 262537412640768000

        // Calculate term = M * L / X
        mpf_mul(term, M, L);            // term = M * L
        mpf_div(term, term, X);         // term /= X

        // Update S
        if (k % 2 == 0) {
            mpf_add(S, S, term);        // S += term
        } else {
            mpf_sub(S, S, term);        // S -= term
        }
    }

    // Final calculation of Pi
    mpf_sqrt_ui(temp, 10005);           // temp = sqrt(10005)
    mpf_mul_ui(temp, temp, 426880);     // temp *= 426880
    mpf_div(pi, temp, S);               // pi = temp / S

    // Clear variables
    mpf_clears(K, M, X, L, S, term, temp, sixteen, NULL);
}

int main() {
    int digits = 100; // Desired precision in decimal digits
    int precision_bits = digits * 3.32193; // Convert to bits (log2(10) ≈ 3.32)
    precision_bits += 20; // Add extra bits for safety during intermediate calculations

    mpf_set_default_prec(precision_bits); // Set the precision
    mpf_t pi;
    mpf_init(pi);

    int iterations = 50; // Use enough iterations to reach desired precision
    calculate_pi(pi, iterations);

    // Print result
    gmp_printf("Calculated value of Pi (to %d digits):\n%.Ff\n", digits, pi);

    mpf_clear(pi);
    return 0;
}
