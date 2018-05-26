#include "status_led.h"

namespace DynamicStatusLed {

    StatusLed::StatusLed(PinName pin)
        : out(pin) {
        out = 0;
        currentState = 0;
        type = PERIODIC;
        iterations = 0;
        currentIteration = 0;
    }

    void StatusLed::add_to_sequence(LedState::State state, int timeMs) {
        LedState ledstate(state, timeMs);
        add_to_sequence(ledstate);
    }

    void StatusLed::add_to_sequence(LedState state) {
        sequence.push_back(state);
    }

    void StatusLed::start(void) {
        currentState = 0;
        currentIteration = 0;
        if (sequence.size() > 0) {
            apply_current_state(); 
        }
    }

    void StatusLed::stop(void) {
        timer.detach();
    }

    void StatusLed::set_iterations(int count) {
        type = TRIGGERED;
        this->iterations = count;
        currentIteration = 0;
    }

    void StatusLed::event_handler(void) {
        currentState = (currentState + 1) % sequence.size();
        timer.detach();

        if (currentState == 0 && type == TRIGGERED) {
            if (currentIteration++ >= iterations) {
                stop();
                return;
            }
        }

        apply_current_state(); 
    }

    void StatusLed::apply_current_state(void) {
        LedState state = sequence.at(currentState);
        out = (state.get_state() == LedState::LED_ON ? 1 : 0 ); 
        timer.attach(callback(this, &StatusLed::event_handler), state.get_time_ms()/1000.0);
    }

};