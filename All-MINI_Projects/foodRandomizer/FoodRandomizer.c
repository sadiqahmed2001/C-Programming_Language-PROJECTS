#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to suggest a random recipe
void suggestRandomRecipe() {
    // Array of sample recipes
    char *recipes[] = {
        "Spaghetti Carbonara",
        "Chicken Stir-Fry",
        "Vegetable Curry",
        "Grilled Salmon with Asparagus",
        "Caprese Salad",
        "Beef Tacos",
        "Mushroom Risotto",
        "Vegetarian Chili",
        "Pasta Primavera",
        "Greek Salad",
        "Chiken Roll",
        "Furits",
        "Egg burgur",
        "Tea With Cookies"

    };

    // Calculate the number of recipes
    int numRecipes = sizeof(recipes) / sizeof(recipes[0]);

    // Generate a random index
    int randomIndex = rand() % numRecipes;

    // Print the suggested recipe
    printf("Suggested Recipe: %s\n", recipes[randomIndex]);
}

int main() {
    printf("Welcome to the Food Randomizer!\n");
    printf("Let's find you a delicious recipe to try!\n\n");

    // Seed the random number generator
    srand(time(NULL));

    // Suggest a random recipe
    suggestRandomRecipe();

    return 0;
    
}
