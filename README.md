# Modular PI Controller in C

A simple and modular implementation of a PI (Proportional-Integral) controller in C with two modes:

- **Series Mode**
- **Parallel Mode**

---

## Features

- Supports two controller configurations: `CTRL_PI_SERIES` and `CTRL_PI_PARALLEL`
- Easily extendable with different controller types
- Clean API structure with function pointers for polymorphic behavior
- C99 standard, portable, and minimal

---

## Build Instructions

```bash
mkdir build && cd build
cmake ..
make
```

---

## File Structure

```
.
├── PiController.c/h      # Core PI controller logic
├── Controller.h          # Shared controller types and interface
├── CMakeLists.txt
```

---

## Example Output

```bash
Control Output: 2.200000
```

---

## Usage

```c
ControllerProp_t prop = {
  .type = CTRL_PI_SERIES,
  .coef.pid = {
    .kp = 1.0,
    .ki = 0.1,
    .kd = 0.0,
    .errOld = 0.0,
    .errSum = 0.0,
    .outPut = 0.0
  }
};

Controller_t *controller = getPiController(&prop);
double result = controller->control(controller, setPoint, measurement, min, max);
```

---

## License

MIT
