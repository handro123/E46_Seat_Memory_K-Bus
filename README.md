# E46 Seat Memory K-Bus with Arduino and LIN-Bus breakout board
Enabling the E46 Seat Memory with Arduino and LIN-Bus breakout board to send K-Bus messages. 

# Source
Thank you to [Cars Electronics and Machining](https://www.youtube.com/@carselectronicsandmachinin4905) on YouTube for the great video that shows how to do this along with the Arduino code. 

[BMW Memory seat function, without the car K-BUS using an Arduino, E46 E53 E63](https://www.youtube.com/watch?v=_w843sGQGsc)
[![BMW Memory seat function, without the car K-BUS using an Arduino, E46 E53 E63](https://img.youtube.com/vi/_w843sGQGsc/0.jpg)](https://youtu.be/_w843sGQGsc)

# Hardware
- Arduino Pro Mini (or any Arduino that has required pins)
- LIN-Bus breakout board. I used the SK Pang one purchased from Copperhill Technologies:
  - [SK Pang LIN-Bus breakout board](https://www.skpang.co.uk/products/lin-bus-breakout-board)
  - [Copperhill Tech link to buy](https://copperhilltech.com/lin-bus-breakout-board/)
- 12v to 5v power converter (plenty on Amazon)

# Wiring
  # 5 volt Wiring
| Arduino | LIN-Bus Breakout Board |
| ------- |:----------------------:|
| VCC     | VCC                    |
| GND     | GND                    |
| TX0     | TXD                    |
| RX1     | RXD                    |
| VCC     | CS                     |

  # 12 volt Wiring
| LIN-Bus Breakout Board | Seat Harness     |
|:----------------------:| ----------------:|
| VBAT                   | 12 v Positive    |
| GND                    | 12 v Negative    |
| LIN                    | K-Bus (Rd/Wh/Yl) |

  # Wiring Diagram
![Arduino Pro Mini LIN Bus drawio](https://github.com/handro123/E46_Seat_Memory_K-Bus/assets/838689/6804743d-521b-4f33-a856-57241bd6940e)


# Demo
Demo video here: https://www.youtube.com/shorts/hXWrDF9REAo

[![Demo Video](https://img.youtube.com/vi/hXWrDF9REAo/0.jpg)](https://youtu.be/hXWrDF9REAo)
