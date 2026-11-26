#include <pwm/channel.hpp>

using namespace mhaa::pwm;

class Incomplete final : public Channel
{
public:
    Status set_duty(DutyPermille duty_permille) override;
    Status set_enabled(bool enabled) override;
};

int main()
{
    Incomplete implementation;
    (void)implementation;
}
