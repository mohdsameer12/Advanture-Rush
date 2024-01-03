//I'll create a simple text-based game where the player interacts with a character and makes choices.
//Let's call it "Adventure Quest."

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to simulate a random event
int getRandomEvent() {
    return rand() % 3;  // Assuming three possible events for simplicity
}

int main() {
    srand(time(NULL));

    printf("Welcome to Adventure Quest!\n");
    

    int playerHealth = 100;
    int playerGold = 0;

    while (playerHealth > 0) {
        printf("\n--- Status ---\n");
        printf("Health: %d\n", playerHealth);
        printf("Gold: %d\n", playerGold);

        printf("\nChoose your action:\n");
        printf("1. Explore\n");
        printf("2. Rest\n");
        printf("3. Quit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nYou embark on an adventure...\n");

                // Simulate a random event
                switch (getRandomEvent()) {
                    case 0:
                        printf("You found a treasure chest! +50 gold!\n");
                        playerGold += 50;
                        break;
                    case 1:
                        printf("You encountered a monster! -20 health!\n");
                        playerHealth -= 20;
                        break;
                    case 2:
                        printf("You discovered a healing potion! +30 health!\n");
                        playerHealth += 30;
                        break;
                }
                break;

            case 2:
                printf("\nYou decide to rest and recover...\n");
                playerHealth += 10;
                printf("You gained 10 health!\n");
                break;

            case 3:
                printf("\nThanks for playing Adventure Quest!\n");
                return 0;

            default:
                printf("\nInvalid choice. Try again.\n");
        }

        // Ensure player health doesn't exceed the maximum (100 in this case)
        if (playerHealth > 100) {
            playerHealth = 100;
        }
    }

    printf("\nGame over! You have run out of health.\n");
    return 0;
}
