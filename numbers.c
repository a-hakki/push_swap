#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_unique_numbers(int n) {
    int *numbers = malloc(n * sizeof(int)); // Allocate memory for n numbers
    if (!numbers) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }

    srand(time(NULL)); // Seed the random number generator
    int count = 0;

    while (count < n) {
        int num = rand() % (n * 10); // Generate a random number in a range (0 to n*10)
        int is_duplicate = 0;

        // Check for duplicates
        for (int i = 0; i < count; i++) {
            if (numbers[i] == num) {
                is_duplicate = 1;
                break;
            }
        }

        // Add the number if it's unique
        if (!is_duplicate) {
            numbers[count] = num;
            count++;
        }
    }

    

    // Print the numbers separated by spaces
    for (int i = 0; i < n; i++) {
        printf("%d", numbers[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");

    free(numbers); // Free allocated memory
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <number_of_unique_integers>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]); // Convert the argument to an integer

    if (n <= 0) {
        printf("Error: The number must be greater than 0.\n");
        return 1;
    }

    generate_unique_numbers(n);

    return 0;
}
