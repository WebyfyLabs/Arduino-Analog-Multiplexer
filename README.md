# AnalogMux
Arduino Library for Analog Multiplexers.

## Usage

Always initialize library instance using `begin` before using it.

### Create Library Instance
```cpp
AnalogMux mux;
```

### Initialization 
#### Without Enable
```cpp
  int8_t selectPins[]{8, 9, 10};
  int8_t selectCount = 3;
  mux.begin(A0, selectCount, selectPins);
```

#### With Enable
```cpp
  int8_t selectPins[]{8, 9, 10};
  int8_t selectCount = 3;

  int8_t enablePin = 12;
  mux.begin(A0, selectCount, selectPins, enablePin);
```

### Read channel
```cpp
    int value = mux.readChannel(3);
```

### Set enable pin 
```cpp
    mux.setEnable(LOW);
```

## Testing

Project building and testing are based on [PlatformIO](https://platformio.org/).

Run unit tests through this command:

```
pio test
```
## References
* [Writing a Library for Arduino](https://www.arduino.cc/en/Hacking/LibraryTutorial)
* [Arduino API Style Guide](https://www.arduino.cc/en/Reference/APIStyleGuide)
* [Arduino Library specification](https://arduino.github.io/arduino-cli/latest/library-specification/)
* [Adafruit - The Well-Automated Arduino Library](https://learn.adafruit.com/the-well-automated-arduino-library)
* [arduino-ad-mux-lib](https://github.com/stechio/arduino-ad-mux-lib)

## Roadmap
- [x] Unit Testing
- [x] Enable Pin Support
- [x] Dynamic Pin Count
- [ ] Automation