#ifndef SALT_DISPENSER_H
#define SALT_DISPENSER_H

#include <stdbool.h>

// SaltDispenser structure
typedef struct {
    float dispense_rate;   // Dispensing rate (grams/second)
    float salt_left;       // Remaining salt (grams)
    bool food_detected;    // Food detection sensor state
    bool actuator_state;   // Actuator state (ON/OFF)
} SaltDispenser;

// Function prototypes
SaltDispenser* create_salt_dispenser();
void set_dispense_rate(SaltDispenser* dispenser, float rate);
void set_salt_left(SaltDispenser* dispenser, float salt);
void set_food_detected(SaltDispenser* dispenser, bool detected);
void control_dispensing(SaltDispenser* dispenser);
void free_salt_dispenser(SaltDispenser* dispenser);

#endif // SALT_DISPENSER_H
