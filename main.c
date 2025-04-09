#include <stdio.h>
#include <string.h>

// Define the country structs to hold data for each card
struct Country {
    char name[50];
    char state[2];
    int population;
    float area;
    float pib; // in billions
    float density;
    int tourist_points;
};

// Array of countries with predefined data
const struct Country countries[] = {
    {"São Paulo", "SP", 12300000, 1521.11f, 699.28f, 12300000 / 1521.11f, 50},
    {"Rio de Janeiro", "RJ", 6748000, 1200.25f, 300.50f, 6748000 / 1200.25f, 30}
};

// Function to print country information
void printCountry(const struct Country* country) {
    printf("Name: %s\nState: %s\n", country->name, country->state);
    printf("Population: %d\nArea: %.2f km²\nPIB: %.2f bilhões\nDensity: %.2f hab/km²\nTourist Points: %d\n\n",
           country->population, country->area, country->pib,
           country->density, country->tourist_points);
}

// Function to calculate total score based on two attributes
float calculateTotalScore(const struct Country* country1, const struct Country* country2, int attr1, int attr2) {
    float score1 = country1->attr1 + country1->attr2;
    float score2 = country2->attr1 + country2->attr2;

    return (score1 > score2) ? score1 : score2;
}

// Main function to implement the comparison
int main() {
    // Print initial message
    printf("Welcome to Super Trunfo Advanced Comparison System\n");
    printf("Choose two attributes for comparison:\n");

    int selected_attrs[2];
    int current_selection = 0;

    do {
        printf("Available attributes: POPULACAO, AREA, PIB, DENSIDADE, PONTOS_TURISTICOS\n");

        // First attribute selection
        if (current_selection == 0) {
            printf("Enter the first attribute number:\n");
            scanf("%d", &selected_attrs[0]);

            // Validate input
            if (selected_attrs[0] < 1 || selected_attrs[0] > 5) {
                printf("Invalid selection. Try again.\n");
                continue;
            }

            current_selection++;
        } else {
            // Second attribute selection must be different
            do {
                printf("Enter the second attribute number (different from %d):\n", selected_attrs[0]);
                scanf("%d", &selected_attrs[1]);

                if (selected_attrs[1] == selected_attrs[0]) {
                    printf("Second attribute cannot be the same as the first. Try again.\n");
                    continue;
                }

                if (selected_attrs[1] < 1 || selected_attrs[1] > 5) {
                    printf("Invalid selection. Try again.\n");
                    continue;
                }

                current_selection++;
            } while (true);
        }
    } while (current_selection != 2);

    // Validate attribute numbers
    if (selected_attrs[0] == selected_attrs[1]) {
        printf("Error: Second attribute must be different from the first. Exiting...\n");
        return 1;
    }

    // Retrieve country attributes based on selected indices
    int attr_index[] = {selected_attrs[0]-1, selected_attrs[1]-1};

    struct Country* card1 = &countries[0];
    struct Country* card2 = &countries[1];

    switch (attr_index[0]) {
        case 0: // Population
            card1->attr1 = card1->population;
            break;
        case 1: // Area
            card1->attr1 = card1->area;
            break;
        case 2: // PIB
            card1->attr1 = card1->pib * 1000000000; // Convert to billions as per original code
            break;
        case 3: // Density
            card1->attr1 = card1->density;
            break;
        case 4: // Tourist Points
            card1->attr1 = card1->tourist_points;
            break;
    }

    switch (attr_index[1]) {
        case 0: // Population
            card2->attr2 = card2->population;
            break;
        case 1: // Area
            card2->attr2 = card2->area;
            break;
        case 2: // PIB
            card2->attr2 = card2->pib * 1000000000; // Convert to billions as per original code
            break;
        case 3: // Density
            card2->attr2 = card2->density;
            break;
        case 4: // Tourist Points
            card2->attr2 = card2->tourist_points;
            break;
    }

    float total1 = calculateTotalScore(card1, card2, attr_index[0], attr_index[1]);
    float total2 = calculateTotalScore(card2, card1, attr_index[1], attr_index[0]); // Swap for comparison

    if (total1 > total2) {
        printf("Card 1 (São Paulo) has a higher total score of %.2f vs Card 2's %.2f\n",
               total1, total2);
    } else if (total2 > total1) {
        printf("Card 2 (Rio de Janeiro) has a higher total score of %.2f vs Card 1's %.2f\n",
               total2, total1);
    } else {
        printf("It's an Empate! Both cards have equal scores.\n");
    }

    // Print all country information
    printCountry(card1);
    printCountry(card2);

    return 0;
}
