#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void tellJoke() {
    char *jokes[] = {
        "Why don't scientists trust atoms?\nBecause they make up everything!",
        "Did you hear about the mathematician who's afraid of negative numbers?\nHe'll stop at nothing to avoid them!",
        "Why don't skeletons fight each other?\nThey don't have the guts!",
        "What do you call fake spaghetti?\nAn impasta!",
        "Why did the scarecrow win an award?\nBecause he was outstanding in his field!",
        "What do you call a fish wearing a bowtie?\nSofishticated!",
        "Why did the bicycle fall over?\nBecause it was two-tired!",
        "What do you call cheese that isn't yours?\nNacho cheese!",
        "What did the policeman say to his hungry stomach? \nFreeze. You,re under a vest.",
        "What did the left eye say to the right eye? Between us,\n something smells!",
        "What do you call a guy who's really loud? \nMike.",
        "Why do birds fly south in the winter? \nIt's faster than walking!",
        "What did the lava say to his girlfriend?\n I lava you!",
        "Why did the student eat his homework? \n Because the teacher told him it was a piece of cake.",
        "What did Yoda say when he saw himself in 4k?\n HDMI.",
        "Which superhero hits home runs? \nBatman!",
        "What's Thanos favorite app on his phone? \nSnapchat.",
        "Sandy's mum has four kids; North, West, East. What is the name of the fourth child?\n Sandy, obviously!",
        "What is a room with no walls? \nA mushroom.",
        "Why did the blue jay get in trouble at school?\n For tweeting on a test!",
        "What social events do spiders love to attend?\n Webbings.",
        "What did one pickle say to the other? \nDill with it",
        "What is brown, hairy and wears sunglasses? \nA coconut on vacation.",
        "Why is a football stadium always cold? \nIt has lots of fans!",
        "What did one math book say to the other? \nI've got so many problems.",
        "What did the Dalmatian say after lunch? \nThat hit the spot!",
        "What do you call two bananas on the floor? \nSlippers.",
        "Why did the chicken cross the playground?\n To get to the other slide.",
        "Why do ducks have feathers on their tails? \nTo cover their butt quacks.",
        "How does a vampire start a letter?\n Tomb it may concern…!!",
        "A plane crashed in the jungle and every single person died. Who survived? \nMarried couples.",
        "What kind of math do birds love? \nOwl-gebra!",
        "Why can't you ever tell a joke around glass? \nIt could crack up.",
        "What do you call a Star Wars droid that takes the long way around? \nR2 detour.",
        "How do you stop an astronaut's baby from crying? \nYou rocket.",
        "Why did the scarecrow win a Nobel prize? \nBecause she was outstanding in her field.",
        "How do you know when a bike is thinking? \nYou can see their wheels turning.",
        "Why was 6 afraid of 7?\n Because 7,8,9.",
        "What goes up and down but doesn't move? \nThe staircase.",
        "What kind of shoes do frogs love? \nOpen-toad!",
        "How did the baby tell his mom he had a wet diaper? \nHe sent her a pee-mail.",
        "What is a witch's favorite subject in school? \nSpelling.",
        "What's brown and sticky? \nA stick.",
        "Why do ducks always pay with cash?\n Because they always have bills!",
        "How did Benjamin Franklin feel holding his kite when he discovered electricity?\n Shocked!",
        "When does a joke become a “dad” joke?\n When the punchline is a parent.",
        "How much did the man sell his dead batteries for?\n Nothing, they were free of charge!"
    };
    
    int numJokes = sizeof(jokes) / sizeof(jokes[0]);
    srand(time(NULL));
    int index = rand() % numJokes;
    
    printf("\n\nHere's a funny joke for you:\n%s\n\n", jokes[index]);
}

int main() {
    char playAgain;
    
    printf("\nWelcome to the Funny Room!\n");
    
    do {
        tellJoke();
        printf("\nDo you want to hear another joke? (y/n): ");
        scanf(" %c", &playAgain);
    } while (playAgain == 'y' || playAgain == 'Y');
    
    printf("Thanks for playing! Hope you had a good laugh!\n");
    
    return 0;
}