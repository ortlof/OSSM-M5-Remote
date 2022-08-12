# Project REMOTE
## The OSSM-M5-Remote

Remote Control Platform for all ESP Controlled Sex Toys. 

![Final Addon](image/remote.png?raw=true "Remote" )

Develop for the OSSM Project: 
https://github.com/KinkyMakers/OSSM-hardware
 
Develop and Design on KinkyMakers Discord: https://discord.gg/MmpT9xE

Supports in this Version:

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

!! Only M5 Stack CORE2 works with this PCB !!

## BOM
BOM is on Octopart for Easy Sourcing: https://octopart.com/bom-tool/rURYMuwB

PCB Files in Folder

## 3D Prints Needed:

| Quantity | Part | Information |
|----------|------|-------------|
| 1x | Bottom.stl | Print with Support 6 Wall 20% Infill | 
| 1x | TOP-*-Keycap-Standoff.stl | Top Depends on your Keycap Cherry or DAS (DSA is wider) | 
| 4x | M5_Remote_Knob_Customizable.scad | If you go for the 3d Printed knobs |

## Assembly 

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

10. Put on Mx Cap and put on Encoder Knobs. 


## Flash Code:

1. Setup Plaformio: https://docs.platformio.org/en/latest/integration/ide/vscode.html#installation
2. Clone or Download This Repo for the Remote 
3. Clone or Download this Repo for the OSSM https://github.com/ortlof/OSSM-Stroke/tree/OSSM_ESP_Remote
4. Flash Code Like Described in this Readme https://github.com/KinkyMakers/OSSM-hardware/blob/master/OSSM%20PlatformIO%20Readme.md

OSSM Remote and OSSM works out of the box right now with 0xFF Broadcast Adresses
Next Versions get OSSM and Remote IDs in Remote to setup. 
~~For safety or when you wan't to use more than one OSSM Remote and OSSM in one Room. ~~
~~You need to set Your MAC adresses acordingly:~~

~~After building both codes they display MAC's in Serial Console.~~
~~Find Line and Change to your OSSM MAC in OSSM code you have to Set the mac of your Remote. ~~

~~MAC in Serial Looks like: 34:86:5D:57:F5:84~~

~~Change to this:~~

~~"#define OSSM 1"~~
~~"uint8_t OSSM_Address[] = {0x34, 0x86, 0x5d, 0x57, 0xf5, 0x84};"~~
