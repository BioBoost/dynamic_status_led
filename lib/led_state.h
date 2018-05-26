#pragma once

namespace DynamicStatusLed {

    class LedState {

        public:
            enum State { LED_OFF, LED_ON };

        public:
            LedState(State state, int timeMs);

        public:
            State get_state(void);
            int get_time_ms(void);

        private:
            State state;
            int timeMs;

    };

};