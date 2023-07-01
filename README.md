# E46 Seat Memory K-Bus with Arduino and LIN-Bus breakout board
Enabling the E46 Seat Memory with Arduino and LIN-Bus breakout board to send K-Bus messages. 

By default this will make the seat think the car is in Ignition Accessory mode. This enables the 1-touch seat adjustment, but you should not leave it in this mode while driving. 

You can change this while the Adruino is powered on and running by temporarily shorting Ground (GND) to the respective Digital I/0 pins 2-6.

You can also change the default when the Arduino powers on by setting a different value in: 
```
byte selected = 3;
```

The different options are: 
| byte selected = | Arduino variable | Description                        |
|-----------------|------------------|------------------------------------|
| 2               | ignitionOff      | Ignition Off                       |
| 3               | ignitionAcc      | Ignition Accessory Position - POS1 |
| 4               | ignitionOn       | Ignition On Position - POS2        |
| 5               | keyRemoved       | Ignition Key Out                   |
| 6               | keyInserted      | Ignition Key In                    |



# Source
Thank you to [Cars Electronics and Machining](https://www.youtube.com/@carselectronicsandmachinin4905) on YouTube for the great video that shows how to do this along with the Arduino code. None of this would have been possible for me without this video, as I would have no idea how to start with the wiring or coding on my own. 

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
|------------------------|:-----------------|
| VBAT                   | 12 v Positive    |
| GND                    | 12 v Negative    |
| LIN                    | K-Bus (Red/White/Yellow dash) |

  # Wiring Diagram
![Arduino Pro Mini LIN Bus drawio](https://github.com/handro123/E46_Seat_Memory_K-Bus/assets/838689/6804743d-521b-4f33-a856-57241bd6940e)


# Demo
Demo video here: https://www.youtube.com/shorts/hXWrDF9REAo

[![Demo Video](https://img.youtube.com/vi/hXWrDF9REAo/0.jpg)](https://youtu.be/hXWrDF9REAo)


# Custom PCB
To go the extra mile I designed a custom PCB to hold the Arduino, LIN-Bus Breakout Board, and a 12v to 5v buck converter. 

![PXL_20230630_161002845](https://github.com/handro123/E46_Seat_Memory_K-Bus/assets/838689/f37561cf-1e64-4811-8283-84a3b6981b9d)


## BOM
| Part | Source | Notes |
|-----------------|------------------|------------------------------------|
| Arduino Pro Mini 5v | https://www.adafruit.com/product/2378 / https://www.sparkfun.com/products/11113      |  |
| SK Pang LIN-Bus Breakout Board | https://www.skpang.co.uk/products/lin-bus-breakout-board      |  |
| HiLetgo 5pcs LM2596S-ADJ Power Module DC-DC Buck Regulator 3A Adjustable 5V/12V/24V | https://www.amazon.com/dp/B00LTSC564/ | MAKE SURE TO SET IT TO 5V BEFORE PLUGGING INTO ARDUINO |
| 100pcs Male Header Pins, Lystaii Straight Single Row 40 Pin 0.1 Inch (2.54mm) Male Pin Header Connector PCB Board Pin Connector Electronic Component Raw Materials | https://www.amazon.com/dp/B06ZZN8L9S/ | |
| Ruibapa 120PCS 2.54mm Female Pin Header Socket Connector Strip Assortment Kit Straight Single Row PCB Board Pin Header 4,6,8,10,12,16,20,40Pin P-037 | https://www.amazon.com/dp/B0B96WXT46/ | |
| OCR 180Pcs Tactile Push Button Switch 10 Values 6x6mm Micro Momentary Tact Button Switches Assortment Kit | https://www.amazon.com/dp/B01MRP025V/ | The buttons should be able to go on either the front or the back. |
| PCB Terminal Blocks, Header, Wire-to-Board, 3 Position, .138 in [3.5 mm] Centerline, 1 Row, 30 – 14 AWG Wire Size, .05 – 2 mm² Wire Size | https://www.te.com/usa-en/product-284512-3.html / https://www.digikey.com/en/products/detail/284512-3/A98397-ND/1131591 | You may be able to find a substitute on Amazon, but the spacing and offset from the edge of the PCB is specifically for this. |
| PCB Terminal Blocks, Plug, Wire-to-Board, 3 Position, .138 in [3.5 mm] Centerline, 1 Row, 180° Wire Entry Angle, 30 – 14 AWG Wire Size | https://www.te.com/usa-en/product-284506-3.html / https://www.digikey.com/en/products/detail/284506-3/A98374-ND/1131590 | You may be able to find a substitute on Amazon. |
| MakerSpot Raspberry Pi Nylon Standoff Kit M2.5 Screws Nuts Spacers Standoffs 210pcs for DIY Building of Raspberry Pi 4 Pi 3 Pi Zero FPV RC Quadcopter Drone PC Mods | https://www.amazon.com/gp/product/B0788FR59P/ | For the LIN-Bus Breakout Board and 12v to 5v buck converter to hold them in place. |

## Assembly

I soldered female headers onto the PCB and male header pins onto everything to make it easily removeable if needed. Only place where I couldn't find headers were for the 3.5mm pitch on the LIN-Bus Breakout Board output, so those wires are soldered to the PCB and then screw into the terminal block. Alternativly you can solder everything directly to the PCB and use some 3.5mm pitch male headers like this: 
https://www.digikey.com/en/products/detail/te-connectivity-amp-connectors/1986717-3/3283614

![3-5mm_pitch_header-1986717-3](https://github.com/handro123/E46_Seat_Memory_K-Bus/assets/838689/d4dfacfe-0f54-4989-81d5-a58356d82baa)



## Pictures
Front of PCB: 
![PXL_20230630_155656246](https://github.com/handro123/E46_Seat_Memory_K-Bus/assets/838689/e4e0d1d1-314c-45d8-ad3a-52da56d4075e)
![pcb-front](https://github.com/handro123/E46_Seat_Memory_K-Bus/assets/838689/0c7a70c1-d17f-4732-8344-29a56eda3ec3)

Back of PCB: 
![PXL_20230630_155009117](https://github.com/handro123/E46_Seat_Memory_K-Bus/assets/838689/aa4c6040-f455-4c39-8c1b-72ecd2d7d8e6)
![pcb-back](https://github.com/handro123/E46_Seat_Memory_K-Bus/assets/838689/4cfae35e-697e-4476-9441-d9822cb13b5b)

