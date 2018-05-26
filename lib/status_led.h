#pragma once

#include "led_state.h"
#include "mbed.h"
#include <vector>

namespace DynamicStatusLed {

    class StatusLed {
        private:
            enum Type { PERIODIC, TRIGGERED };

        public:
            StatusLed(PinName pin);

        public:
            void add_to_sequence(LedState::State state, int timeMs);
            void add_to_sequence(LedState state);
            void start(void);
            void stop(void);
            void set_iterations(int count);

        private:
            void event_handler(void);
            void apply_current_state(void);

        private:
            DigitalOut out;
            Timeout timer;
            std::vector<LedState> sequence;
            int currentState;

            Type type;
            int iterations;
            int currentIteration;
    };

};