# Porting the PWM Contract

Hardware Definitions describe timer resolution, outputs and supported waveform facilities. The Adapter chooses a hardware realization and reports rate tolerance and supported alignments. Different counters can quantize the same duty differently, and coupled channels can share a rate. The API neither exposes timer bit depth nor guarantees a glitchless update boundary.

This repository's host simulations and shared API compile/link checks provide source-level evidence. Target timing and physical behavior require hardware validation.
