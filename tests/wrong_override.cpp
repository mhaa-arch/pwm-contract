#include <pwm/channel.hpp>

using namespace mhaa::pwm;

class WrongOverride final : public Channel
{
public:
    Status configure(uint32_t frequency_hz, Alignment alignment) const override;
};
