#include <stdio.h>

void mult(int N, int K);
void recursive_diamond(int N, int originalN);
void recursive_full_diamond(int N, int originalN);

int main() {
    mult(10, 10);

    printf("\n\n");

    recursive_diamond(10, 10);

    printf("\n\n");

    recursive_full_diamond(10, 10);
}

void mult(int N, int K) {
    if (K > 0) {
        mult(N, K - 1);
        printf("%d * %d = %d\n", N, K, N * K);
    }
}

void recursive_diamond(int N, int originalN) {
    if (N > 0) {
        recursive_diamond(N - 1, originalN);
        for (int i = 0; i < originalN - N; i++) {
            printf(" ");
        }
        for (int i = 0; i < 2 * (10 - N) - 1; i++) {
            printf("*");
        }
        printf("\n");
    }
}

void recursive_full_diamond(int N, int originalN) {
    if (N > 0) {
        recursive_full_diamond(N - 1, originalN);
        for (int i = 0; i < originalN - N; i++) {
            printf(" ");
        }
        for (int i = 0; i < 2 * N - 1; i++) {
            printf("*");
        }
        printf("\n");
    }
    if (N == originalN) {
        for (int i = originalN - 1; i > 0; i--) {
            for (int j = 0; j < originalN - i; j++) {
                printf(" ");
            }
            for (int j = 0; j < 2 * i - 1; j++) {
                printf("*");
            }
            printf("\n");
        }
    }
}