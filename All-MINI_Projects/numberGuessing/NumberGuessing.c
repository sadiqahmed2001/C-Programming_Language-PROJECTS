#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int number, guess, attempts = 0;
    srand(time(0)); // Seed for random number generation
    number = rand() % 100 + 1; // Generate random number between 1 and 100

    printf("Welcome to the Number Guessing Game!\n");
    printf("Guess the number between 1 and 100.\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess > number) {
            printf("Too high! Try again.\n");
        } else if (guess < number) {
            printf("Too low! Try again.\n");
        } else {
            printf("Congratulations! You guessed the number %d in %d attempts!\n", number, attempts);
        }
    } while (guess != number);

    return 0;
}