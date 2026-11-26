#ifndef MHAA_PWM_TYPES_HPP
#define MHAA_PWM_TYPES_HPP

#include <stdint.h>

namespace mhaa
{
    namespace pwm
    {
        enum class Alignment
        {
            Edge,
            Center
        };
        enum class Polarity
        {
            ActiveHigh,
            ActiveLow
        };
        using DutyPermille = uint16_t;

        enum class Status
        {
            Success,
            InvalidArgument,
            Unsupported,
            Error
        };
    }
}

#endif
