#include "led_state.h"

namespace DynamicStatusLed {

    LedState::LedState(State state, int timeMs) {
        this->state = state;
        this->timeMs = timeMs;
    }

    LedState::State LedState::get_state(void) {
        return state;
    }

    int LedState::get_time_ms(void) {
        return timeMs;
    }

};