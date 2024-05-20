#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> // Include string.h for strchr function

// Function to suggest a random recipe along with its price
char* suggestRandomRecipe(float* price) {
    // Array of sample recipes and their corresponding prices
    char *recipes[] = {
        "Spaghetti Carbonara - $10.00",
        "Chicken Stir-Fry - $8.50",
        "Vegetable Curry - $7.00",
        "Grilled Salmon with Asparagus - $12.00",
        "Caprese Salad - $6.50",
        "Beef Tacos - $9.00",
        "Mushroom Risotto - $8.00",
        "Vegetarian Chili - $7.50",
        "Pasta Primavera - $9.50",
        "Greek Salad - $6.00",
        "Chiken Roll - $5.50",
        "Furits - $3.00",
        "Egg burgur - $5.00",
        "Tea With Cookies - $4.50"
    };

    // Calculate the number of recipes
    int numRecipes = sizeof(recipes) / sizeof(recipes[0]);

    // Generate a random index
    int randomIndex = rand() % numRecipes;

    // Extract the recipe and price
    char* suggestedRecipe = recipes[randomIndex];
    char* priceStr = strchr(suggestedRecipe, '$'); // Find the '$' sign
    *price = atof(priceStr + 1); // Convert the price string to a float

    // Return the suggested recipe
    return suggestedRecipe;
}

// Function to display the menu and return the price of selected tea
float displayMenu() {
    printf("\nMenu:\n");
    printf("1. Black Tea - $3.00\n");
    printf("2. Green Tea - $4.00\n");
    printf("3. Masala Chai - $3.50\n");
    printf("4. Food Recipes\n");
    printf("5. Quit\n");

    int choice;
    float price = 0;

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            price = 3.00;
            break;
        case 2:
            price = 4.00;
            break;
        case 3:
            price = 3.50;
            break;
        case 4: {
            float recipePrice;
            char* suggestedRecipe = suggestRandomRecipe(&recipePrice);
            printf("Suggested Recipe: %s\n", suggestedRecipe);
            price = recipePrice;
            break;
        }
        case 5:
            printf("Thank you for visiting!\n");
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return price;
}

int main() {
    printf("Welcome to the Food Randomizer!\n");
    printf("Let's find you a delicious recipe to try!\n\n");

    // Seed the random number generator
    srand(time(NULL));

    // Display the tea menu
    float teaPrice = displayMenu();
    
    if (teaPrice > 0) {
        printf("You selected a tea. Please pay $%.2f at the counter.\n", teaPrice);
    }

    return 0;
}







