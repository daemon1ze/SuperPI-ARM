#include <iostream>
#include <gmp.h>
#include <cmath>
#include <pthread.h>

// Function prototypes
void* computePI(void* precision);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " [precision]" << std::endl;
        return 1;
    }

    int precision = std::atoi(argv[1]);
    pthread_t thread_id;

    // Start a thread to compute PI
    pthread_create(&thread_id, NULL, computePI, &precision);

    // Wait for the computation to finish
    pthread_join(thread_id, NULL);

    return 0;
}

void* computePI(void* precisionPtr) {
    int precision = *(int*)precisionPtr;
    mpf_set_default_prec(precision);

    mpf_t a, b, t, p, a_next, pi;
    mpf_inits(a, b, t, p, a_next, pi, NULL);

    // Initialize variables
    mpf_set_d(a, 1.0); // a = 1
    mpf_sqrt_ui(b, 2); // b = sqrt(2)
    mpf_ui_div(b, 1, b); // b = 1/sqrt(2)
    mpf_set_d(t, 0.25); // t = 1/4
    mpf_set_ui(p, 1); // p = 1

    for (int i = 0; i < precision; ++i) {
        // Compute a_next = (a + b) / 2
        mpf_add(a_next, a, b);
        mpf_div_ui(a_next, a_next, 2);

        // Compute b = sqrt(a * b)
        mpf_mul(b, a, b);
        mpf_sqrt(b, b);

        // Compute t -= p * (a - a_next) * (a - a_next)
        mpf_sub(a, a, a_next);
        mpf_mul(a, a, a);
        mpf_mul(a, a, p);
        mpf_sub(t, t, a);

        // Update a = a_next
        mpf_set(a, a_next);

        // Update p = 2 * p
        mpf_mul_ui(p, p, 2);
    }

    // Compute pi = (a + b) * (a + b) / (4 * t)
    mpf_add(pi, a, b);
    mpf_mul(pi, pi, pi);
    mpf_div_ui(pi, pi, 4);
    mpf_div(pi, pi, t);

    gmp_printf("Computed PI: %.Ff\n", pi);

    // Clean up
    mpf_clears(a, b, t, p, a_next, pi, NULL);
    pthread_exit(NULL);
}
