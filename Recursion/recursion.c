#include <stdio.h>
#include <string.h>

void mult(int N, int K);
void recursive_diamond(int N, int originalN);
void recursive_full_diamond(int N, int originalN);
int zeroes(int n);
int zeroes_user(int n, int choice);
void convert(int n, char* result);

int main() {
    mult(10, 10);

    printf("\n\n");

    recursive_diamond(10, 10);

    printf("\n\n");

    recursive_full_diamond(10, 10);

    printf("\n\n");

    printf("%d\n", zeroes(1020304050));

    printf("\n\n");

    printf("%d\n", zeroes_user(0, 0));

    printf("\n\n");

    char result[100] = "";
    convert(123, result);
    printf("%s\n", result);
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

int zeroes(int n) {
	if (n == 0) return 1;
	else if (n < 10) return 0;
	
	if (n % 10 == 0) return 1 + zeroes(n / 10);
	else return zeroes(n / 10);
}

int zeroes_user(int n, int choice) {
	if (n == 0) return 1;
	else if (n < 10) return 0;
	
	if (n % 10 == choice) return 1 + zeroes(n / 10);
	else return zeroes(n / 10);
}

void convert(int n, char* result) {
    static const char* mapping[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    if (n == 0) return;
    convert(n / 10, result);
    strcat(result, mapping[n % 10]);
    strcat(result, " ");
}