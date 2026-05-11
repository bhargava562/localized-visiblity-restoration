# Thermal Sandwich Assembly (Phase 1 Validation)

LOVRS uses a compact thermoelectric stack to induce local condensation in the **0.9–1.5m Driver Optical Corridor**.

## Stack Order

1. **Fan**
2. **Heatsink**
3. **Peltier Module (TEC1-12706)**
4. **Cold Plate**

## Why This Order

- The fan continuously removes heat from the hot side through the heatsink.
- The Peltier creates a thermal gradient across the stack.
- The cold plate becomes the condensation surface facing the target optical zone.

## Integration Notes

- Use thermal paste on both sides of each Peltier module.
- Clamp pressure must be even to avoid module stress and poor thermal contact.
- Route condensate safely for collection/reuse (e.g., dust suppression feed).
- Start with one module for validation, then scale to 4 modules in controlled steps.
