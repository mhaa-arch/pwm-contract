# PWM Contract example

[The conformance program](../tests/conformance.cpp) pairs a simulated implementation with assertions at the Contract boundary. The polarity fixture shows how to expose one supported setting and reject another. The base channel fake rejects center alignment, accepts 1 kHz edge alignment and a duty of 600 thousandths, then toggles its simulated output enable. These results represent the fake's capabilities rather than an MCU profile.

## Implementation excerpt

This class is taken from the program. The linked source contains the test cases and any additional fixtures.

```cpp
#include <pwm/channel.hpp>
#include <pwm/polarity_control.hpp>


using namespace mhaa::pwm;

class FakePolarity final : public PolarityControl
{
public:
    Status set_polarity(Polarity polarity) override
    {
        return polarity == Polarity::ActiveHigh ? Status::Success : Status::Unsupported;
    }
};
```

## Build and run

From this repository root, with assertions enabled, compile the full program. A passing run exits with status 0 and prints no output. Use `conformance.exe` on Windows.

```sh
g++ -std=c++11 -Wall -Wextra -Wpedantic -Werror -fno-rtti -fno-exceptions -Iinclude tests/conformance.cpp -o conformance
./conformance
```

To verify enforcement of the abstract interface, compile the two negative sources separately. The first should diagnose an abstract type and the second an incompatible override.

```sh
g++ -std=c++11 -Wall -Wextra -Wpedantic -Werror -fno-rtti -fno-exceptions -Iinclude -fsyntax-only tests/missing_override.cpp
g++ -std=c++11 -Wall -Wextra -Wpedantic -Werror -fno-rtti -fno-exceptions -Iinclude -fsyntax-only tests/wrong_override.cpp
```
