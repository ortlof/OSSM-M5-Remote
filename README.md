# Project REMOTE
## The OSSM-M5-Remote

A Remote Control Platform for all ESP Controlled Sex Toys,with a focus on the OSSM and related toys.

![Final Addon](image/remote.png?raw=true "Remote" )

Intially developed for the OSSM Project: 
https://github.com/KinkyMakers/OSSM-hardware
 

To help with development and design join the KinkyMakers Discord: https://discord.gg/MmpT9xE . Be sure to say hello in the #m5-remote channel. 

Supported in this version of the M5 remote:
## Supported toys in this version

| OSSM Machine | https://github.com/KinkyMakers/OSSM-hardware |

| EJECT | https://github.com/ortlof/EJECT-cum-tube-project |

# Build IT Yourself

## Parts Needed:

| Quantity | Part | Sourcing EU | Price € |
|----------|------|-------------|---------|
| 2x | M3x25mm Allen key | https://www.amazon.de/Edelstahl-Innensechskant-Bolzenset-Eisenrahmen-Mechanischer-Innensechskantschraube-Mutternset/dp/B07PPFT871/ | 12,97 € | 
| 4x | Heat Set inserts M3 | https://www.amazon.de/ruthex-Gewindeeinsatz-St%C3%BCck-Gewindebuchsen-Kunststoffteile/dp/B08BCRZZS3 | 8,99 € |
| 4x | M3x20mm Allen Key | " | " |
| 1x | M5 STACK CORE2 | https://www.distrelec.de/de/esp32-m5core2-entwicklungsmodul-m5stack-k010/p/30181494 | 46,59 € |
| 1x | 3,7v 2000mAh Lipo Batterie Size 34,5 mm x 10,6 mm x 56 mm | https://www.amazon.de/EEMB-103454-2AhLithium-Schutzplatine-Isolationsbeschichtung/dp/B08214DJLJ/ | 14,89 € |
| 4x | Encoder Knob Bought or 3D Printed | https://de.aliexpress.com/item/1005001394286414.html | 5 € |
| 1x | M5 Remote PCB | KinyMaker Discord M5-Remote Channel or https://www.pcbway.com/project/shareproject/M5Stack_Core2_Remote_Plattform_2cb5bac0.html | 15 € |

!! IMPORTANT!: Only the M5 Stack CORE2 works with this PCB !!

## BOM
BOM is on Octopart for Easy Sourcing: https://octopart.com/bom-tool/rURYMuwB

PCB Files are located in the /OSSM-M5-Remote/Hardware/PCB folder 

## 3D Prints Needed:

| Quantity | Part | Information |
|----------|------|-------------|
| 1x | Bottom.stl or Bottom_Adafruit_LIPO.stl| There is a specific version for the wider Adafruit LIPO battery. Print with Support 6 Wall 20% Infill | 
| 1x | TOP-*-Keycap-Standoff.stl | Top Depends on your Keycap Cherry or DAS (DSA is wider) | 
| 4x | M5_Remote_Knob_Customizable.scad | If you go for the 3d Printed knobs |

Filament - A good quality PLA works well. While there are no threads it is recommended that your printer is well calibrated.  

## Assembly 

Due to a lack of standardisation in LIPO battery polarity it is important to verify how yours is configured. If the battery is reversed it will result in the CORE M5 Stack being damaged.

1. Remove Core M5 MIC/MPU Module from M5 core Bottom, Unscrew the Grey bottom and remove internal battery. 
2. Glue battery with 3m Tape to Bottom Part.

![1](image/bottom+battery.jpg?raw=true "1" )

3. Connect Core M5 MIC/MPU Module to Bottom Connector on PCB.
4. Check Battery pinout and change if needed the pins on battery Connector.
5. Connect Battery to PCB.

![2](image/bottom+pcb.png?raw=true "2" )

6. Insert PCB into Bottom Print. 
7. Connect M5 Core with PCB and Screw with 25mm M3 Bolts to Case.

![3](image/bottom+m5.jpg?raw=true "3" )

8. Heatsink M3 inserts into Top Print.
9. Put top on Remote and Screw with 4x M3 20mm to the Case.

![4](image/full-remote.jpg?raw=true "4" )

10. Install the Mx Cap and Encoder Knobs. 


## Flash Code:

1. Setup Plaformio: https://docs.platformio.org/en/latest/integration/ide/vscode.html#installation
2. Clone or Download This Repo for the Remote 
3. Clone or Download this Repo for the OSSM https://github.com/ortlof/OSSM-Stroke
4. Flash Code Like Described in this Readme https://github.com/KinkyMakers/OSSM-hardware/blob/master/OSSM%20PlatformIO%20Readme.md

If you are one of the very small number of Version 1 PCB users, you will need to change your version to V1 in the config.h. The current version in GitHub is V2.
