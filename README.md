# E46 Seat Memory K-Bus with Arduino and LIN-Bus breakout board
Enabling the E46 Seat Memory with Arduino and LIN-Bus breakout board to send K-Bus messages. 


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
![Arduino Pro Mini LIN Bus](/Arduino%20Pro%20Mini%20LIN%20Bus.png)

