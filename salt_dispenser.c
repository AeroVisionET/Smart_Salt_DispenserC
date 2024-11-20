#include "salt_dispenser.h"
#include <stdio.h>
#include <stdlib.h>

// Create a new SaltDispenser object
SaltDispenser* create_salt_dispenser() {
    SaltDispenser* dispenser = (SaltDispenser*)malloc(sizeof(SaltDispenser));
    if (dispenser == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    dispenser->dispense_rate = 0.0f;
    dispenser->salt_left = 0.0f;
    dispenser->food_detected = false;
    dispenser->actuator_state = false;
    return dispenser;
}

// Set the dispensing rate
void set_dispense_rate(SaltDispenser* dispenser, float rate) {
    dispenser->dispense_rate = rate;
}

// Set the remaining salt amount
void set_salt_left(SaltDispenser* dispenser, float salt) {
    dispenser->salt_left = salt;
}

// Set food detection status
void set_food_detected(SaltDispenser* dispenser, bool detected) {
    dispenser->food_detected = detected;
}

// Control the dispensing logic
void control_dispensing(SaltDispenser* dispenser) {
    if (dispenser->food_detected && dispenser->salt_left > 0 && dispenser->dispense_rate > 0) {
        dispenser->actuator_state = true;
        dispenser->salt_left -= dispenser->dispense_rate;
        printf("Dispensing salt. Remaining salt: %.2f grams.\n", dispenser->salt_left);
    } else {
        dispenser->actuator_state = false;
        printf("Actuator OFF: ");
        if (!dispenser->food_detected) printf("No food detected. ");
        if (dispenser->salt_left <= 0) printf("Out of salt. ");
        if (dispenser->dispense_rate <= 0) printf("Dispense rate is zero. ");
        printf("\n");
    }
}

// Free the SaltDispenser object
void free_salt_dispenser(SaltDispenser* dispenser) {
    free(dispenser);
}
