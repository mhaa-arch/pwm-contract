#ifndef MHAA_PWM_CHANNEL_HPP
#define MHAA_PWM_CHANNEL_HPP

#include <stdint.h>
#include <pwm/types.hpp>

namespace mhaa
{
    namespace pwm
    {
        /** @brief Configures and controls one PWM output channel. */
        class Channel
        {
        public:
            virtual ~Channel() = default;

            /** @brief Requests a nonzero nominal frequency and alignment. */
            virtual Status configure(uint32_t frequency_hz, Alignment alignment) = 0;

            /** @brief Sets the active fraction in thousandths, from 0 to 1000. */
            virtual Status set_duty(DutyPermille duty_permille) = 0;
            virtual Status set_enabled(bool enabled) = 0;
        };
    }
}

#endif
