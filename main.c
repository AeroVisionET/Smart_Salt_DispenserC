#include <stdio.h>
#include "salt_dispenser.h"

int main() {
    // Create a SaltDispenser object
    SaltDispenser* dispenser = create_salt_dispenser();

    // Set initial parameters
    set_salt_left(dispenser, 10.0f);      // 10 grams of salt available
    set_dispense_rate(dispenser, 2.0f);  // Dispense 2 grams/second

    // Simulate food detection and dispensing
    set_food_detected(dispenser, true);
    control_dispensing(dispenser); // Dispense salt

    // Simulate no food detected
    set_food_detected(dispenser, false);
    control_dispensing(dispenser); // Actuator turns OFF

    // Simulate salt running out
    set_salt_left(dispenser, 0.0f);
    set_food_detected(dispenser, true);
    control_dispensing(dispenser); // Actuator remains OFF

    // Free the SaltDispenser object
    free_salt_dispenser(dispenser);

    return 0;
}
