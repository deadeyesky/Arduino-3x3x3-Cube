# Arduino-3x3x3-Cube
Arduino Uno, Nano, and Mega and ATtiny85.

This code is still a work in progress and needs refining. Furthermore, I will add a seperate header file for the functions to occupy.

The boards that this code supports the [Arduino Uno](https://store.arduino.cc/usa/arduino-uno-rev3), [Arduino Nano](https://store.arduino.cc/usa/arduino-nano), [Arduino Mega](https://store.arduino.cc/usa/mega-2560-r3), and the [ATtiny84-20PU](https://www.arrow.com/en/products/attiny84-20pu/microchip-technology).

| Board Type | Row Assignment | Column Assignment |
| ------------- | ------------- | ------------- |
| Uno | `A1, A2, A3` | `2, 3, 4, 5, 6, 7, 8, 9, 10` |
| Nano | `A1, A2, A3`  | `2, 3, 4, 5, 6, 7, 8, 9, 10` |
| Mega | `A1, A2, A3`  | `2, 3, 4, 5, 6, 7, 8, 9, 10` |
| ATtiny84 | `A0, A1, A2`  | `2, 3, 4, 5, 6, 7, 8, 9, 10` |

**Important for ATtiny users:** Note that for the ATtiny, a shift bit register will be needed. We used the [74HC595]() for this.
