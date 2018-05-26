#include "mbed.h"
#include "status_led.h"

using namespace DynamicStatusLed;
 
int main() {

    // Bursting
    LedState on(LedState::LED_ON, 100);
    LedState off(LedState::LED_OFF, 100);
    LedState longOff(LedState::LED_OFF, 2000);

    StatusLed alive1(PC_8);
    for (unsigned int i = 0; i < 5; i++) {
        alive1.add_to_sequence(on);
        alive1.add_to_sequence(off);
    }
    alive1.add_to_sequence(longOff);
    alive1.start();

    // Fixed iteration and periodic
    StatusLed alive2(PC_9);
    alive2.add_to_sequence(LedState::LED_ON, 200);
    alive2.add_to_sequence(LedState::LED_OFF, 200);
    alive2.set_iterations(5);
    alive2.start();

    // Low power alive
    StatusLed alive3(PC_10);
    alive3.add_to_sequence(LedState::LED_ON, 50);
    alive3.add_to_sequence(LedState::LED_OFF, 10000);
    alive3.start();

    while (true) {
        wait_ms(1000);
    }
}
