# PWM contract

## Configure one channel

[Channel](../include/pwm/channel.hpp) accepts a positive nominal frequency in hertz and a supported alignment. `DutyPermille` represents 0 through 1000 thousandths of a period. Quantize an intermediate value to the nearest available fraction, with either result allowed at a midpoint. Reject zero or full duty as `Unsupported` if the hardware cannot produce that exact endpoint. Out-of-range inputs are `InvalidArgument`.

The enable call controls whether the output drives the waveform. Define hardware-specific frequency tolerance, disabled output behavior and any restrictions on live reconfiguration. [PolarityControl](../include/pwm/polarity_control.hpp) is optional and selects the active electrical level.

## Implementation boundary

The Adapter owns resource state. The caller must keep the implementation alive during each call and arrange access from other execution contexts. Document the contexts and concurrency guarantees of the actual implementation. Shared public types are in [`pwm/types.hpp`](../include/pwm/types.hpp).
