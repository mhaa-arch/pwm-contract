#ifndef MHAA_PWM_POLARITY_CONTROL_HPP
#define MHAA_PWM_POLARITY_CONTROL_HPP

#include <pwm/types.hpp>

namespace mhaa
{
    namespace pwm
    {
        class PolarityControl
        {
        public:
            virtual ~PolarityControl() = default;
            virtual Status set_polarity(Polarity polarity) = 0;
        };
    }
}

#endif
