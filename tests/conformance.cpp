#include <pwm/channel.hpp>
#include <pwm/polarity_control.hpp>

#include <cassert>

using namespace mhaa::pwm;

class Fake final : public Channel
{
public:
    Status configure(uint32_t frequency_hz, Alignment alignment) override
    {
        if (!frequency_hz)
        {
            return Status::InvalidArgument;
        }
        if (alignment != Alignment::Edge || frequency_hz != 1000)
        {
            return Status::Unsupported;
        }
        configured_ = true;
        return Status::Success;
    }

    Status set_duty(DutyPermille duty) override
    {
        return duty > 1000 ? Status::InvalidArgument : Status::Success;
    }

    Status set_enabled(bool value) override
    {
        if (value && !configured_)
        {
            return Status::Error;
        }
        enabled = value;
        return Status::Success;
    }

    bool enabled = false;

private:
    bool configured_ = false;
};

class FakePolarity final : public PolarityControl
{
public:
    Status set_polarity(Polarity polarity) override
    {
        return polarity == Polarity::ActiveHigh ? Status::Success : Status::Unsupported;
    }
};

int main()
{
    Fake fake;
    Channel &channel = fake;
    assert(channel.configure(1000, Alignment::Center) == Status::Unsupported);
    assert(channel.configure(1000, Alignment::Edge) == Status::Success);
    assert(channel.set_duty(600) == Status::Success);
    assert(channel.set_enabled(true) == Status::Success && fake.enabled);
    assert(channel.set_enabled(false) == Status::Success && !fake.enabled);
    FakePolarity fake_polarity;
    PolarityControl &polarity = fake_polarity;
    assert(polarity.set_polarity(Polarity::ActiveHigh) == Status::Success);
    assert(polarity.set_polarity(Polarity::ActiveLow) == Status::Unsupported);
}
