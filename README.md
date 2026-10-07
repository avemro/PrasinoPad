# PrasinoPad
###### $${\color{gray}\text{Prasino: Prasinos = Green (from greek language)}}$$

Customizable 4-key macropad with the Seeed Studio XIAO RP2040 microcontroller along with Cherry MX switches, an EC11 rotary encoder, and a 0.91" I2C OLED display, which is controlled by QMK firmware[cite: 1].

Depending on whether one needs a media controller, scrubbing for video editing, or simply some hotkeys for application control, PrasinoPad provides the possibility to have everything at hands without unnecessary desk cluttering[cite: 1].

---

## Features

* **Direct-Pin Switching**: As there are only 4 keys, each switch is connected directly to the GPIO pin of the MCU pulled to the ground, eliminating the need for any diode matrix[cite: 2, 5].
* **Rotation Knob**: Alps/EC11 rotary encoder for controlling volume, scrolling, or scrubbing along the timeline, featuring a built-in tactile switch[cite: 1, 2, 5].
* **Status Indicators**: 0.91" 128x32 OLED display over I2C to display active layers, volume level, or status icons[cite: 1, 2, 5].
* **Sleek Microcontroller**: Equipped with the Seeed Studio XIAO RP2040, mounted directly on the underside of the board to keep the desk footprint small[cite: 1, 2].
* **Personalized Shell**: 3D-printed body with special slots for the switch plate, knob, and OLED display[cite: 1].

---

## Hardware Gallery

### Assembled Render
![Hackpad Render](images/assembly.png)

### 3D Printed Enclosure
![Case Assembly](images/case.png)

### KiCad Schematic
![KiCad Schematic](images/schematic.png)

### PCB Layout
![KiCad PCB](images/pcb.png)

---

## Pinout & Wiring

The XIAO RP2040 is soldered to the bottom layer (`B.Cu`) with direct access to all the board components[cite: 2]:

| Component | Function | XIAO Pin (KiCad Net) | RP2040 GPIO | Description |
| :--- | :--- | :--- | :--- | :--- |
| **SW1**[cite: 2, 5] | Key 1[cite: 2, 5] | `D0` (`PA02_A0_D0`)[cite: 2, 5] | GP26 | Pulled low to GND on press[cite: 2, 5] |
| **SW2**[cite: 2, 5] | Key 2[cite: 2, 5] | `D1` (`PA4_A1_D1`)[cite: 2, 5] | GP27 | Pulled low to GND on press[cite: 2, 5] |
| **SW3**[cite: 2, 5] | Key 3[cite: 2, 5] | `D2` (`PA10_A2_D2`)[cite: 2, 5] | GP28 | Pulled low to GND on press[cite: 2, 5] |
| **SW4**[cite: 2, 5] | Key 4[cite: 2, 5] | `D3` (`PA11_A3_D3`)[cite: 2, 5] | GP29 | Pulled low to GND on press[cite: 2, 5] |
| **SW5 (Enc)**[cite: 2, 5] | Channel A[cite: 2, 5] | `D8` (`PA7_A8_D8_SCK`)[cite: 2, 5] | GP4 | Encoder quadrature signal A[cite: 2, 5] |
| **SW5 (Enc)**[cite: 2, 5] | Channel B[cite: 2, 5] | `D9` (`PA5_A9_D9_MISO`)[cite: 2, 5] | GP3 | Encoder quadrature signal B[cite: 2, 5] |
| **SW5 (Switch)**[cite: 2, 5]| Encoder Push[cite: 2, 5]| `D7` (`PB09_A7_D7_RX`)[cite: 2, 5] | GP1 | Pulled low to GND on click[cite: 2, 5] |
| **OLED (J1 Pin 4)**[cite: 2, 5]| I2C SDA[cite: 2, 5] | `D4` (`PA8_A4_D4_SDA`)[cite: 2, 5] | GP6 | Serial Data line[cite: 2, 5] |
| **OLED (J1 Pin 3)**[cite: 2, 5]| I2C SCL[cite: 2, 5] | `D5` (`PA9_A5_D5_SCL`)[cite: 2, 5] | GP7 | Serial Clock line[cite: 2, 5] |
| **OLED (J1 Pin 2)**[cite: 2, 5]| Power[cite: 2, 5] | `3V3`[cite: 2, 5] | 3.3V Rail | Logic power[cite: 2, 5] |
| **OLED (J1 Pin 1)**[cite: 2, 5]| Ground[cite: 2, 5] | `GND`[cite: 2, 5] | Ground | Common system ground[cite: 2, 5] |

---

## Bill of Materials (BOM)

| Item | Qty | Details | Footprint / Notes |
| :--- | :--- | :--- | :--- |
| **Seeed Studio XIAO RP2040**[cite: 1, 2] | 1[cite: 2] | RP2040 microcontroller development board[cite: 1] | Hybrid SMD / THT footprint on PCB rear[cite: 2] |
| **Cherry MX Switches**[cite: 2] | 4[cite: 2] | Standard mechanical keyswitches[cite: 2] | 1.00u PCB mount footprint[cite: 2] |
| **1U Keycaps** | 4 | Standard profile keycaps (OEM / Cherry / XDA) | Fits standard MX stem |
| **EC11 Rotary Encoder**[cite: 1] | 1[cite: 2] | Incremental encoder with tactile push switch[cite: 2, 5] | Alps EC12E vertical footprint[cite: 2] |
| **0.91" OLED Display**[cite: 1] | 1[cite: 2] | 128x32 monochrome I2C display[cite: 1, 2] | 4-pin interface[cite: 2, 5] |
| **Female Pin Header**[cite: 2] | 1[cite: 2] | 1x4 2.54mm pitch female header[cite: 2, 5] | Socket for the OLED screen[cite: 2] |
| **3D Printed Case & Plate**[cite: 1] | 1[cite: 1] | Printed housing (PLA or PETG)[cite: 1] | Case STL files[cite: 1] |
| **Hardware** | 4 | M2 or M3 screws | Secures the plate to the case |

---

## Firmware Configuration

PrasinoPad employs Direct-pin mapping in QMK:

1. **Matrix Mapping**: In your keyboard configuration file, add `DIRECT_PINS` pin mappings for switches with `GP26`, `GP27`, `GP28`, and `GP29`.
2. **Encoders Configuration**: Add `ENCODERS_PAD_A { GP4 }` and `ENCODERS_PAD_B { GP3 }`. The encoder switch will be mapped as a regular key in the direct matrix (`GP1`).
3. **OLED Display**: Add `OLED_ENABLE = yes` and `OLED_DRIVER = SSD1306` in `rules.mk` and configure I2C pins to `GP7` (SCL), `GP6` (SDA).
4. **Programming**:
    * Press the **BOOT** button on the XIAO RP2040 while connecting the USB-C connector.
    * Mount the board as a mass storage device (`RPI-RP2`) and copy your compiled `.uf2` file into that drive.

---

## Assembly Hints

* **Order of Soldering**: First solder the XIAO RP2040 board to the back of the PCB[cite: 2], then the 4-pin OLED header socket[cite: 2], Cherry MX switches[cite: 2] and rotary encoder[cite: 2].
* **OLED Positioning**: With a pin header socket used instead of direct soldering of the display you will be able to adjust its position and make sure that it is level with the window of the case[cite: 1, 2].
* **Printing Parameters**: 0.2mm layer thickness, 3-4 perimeters and 20% fill should give enough stiffness for the switch holes and screw holes[cite: 1].
